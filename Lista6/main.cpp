#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <QVector3D>
#include <QMatrix4x4>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QInputDialog>
#include <QPushButton>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    const int WIDTH = 400;
    const int HEIGHT = 400;

    QApplication a(argc, argv);

    // Setup graphic view
    QGraphicsView view;
    view.setRenderHint(QPainter::Antialiasing);
    view.setRenderHint(QPainter::SmoothPixmapTransform);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create scene
    QGraphicsScene scene(0, 0, WIDTH, HEIGHT);
    view.setScene(&scene);

    // Open file with points data
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open File", QString(), "Text Files (*.txt)");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1;
    }

    // Read points data
    QVector<QVector3D> points;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList coords = line.split(';');
        if (coords.size() == 3) {
            float x = coords[0].toFloat();
            float y = coords[1].toFloat();
            float z = coords[2].toFloat();
            points.append(QVector3D(x, y, z));
        }
    }

    // Create button to rotate points
    /*
    QPushButton *rotateButton = new QPushButton("Rotate");
    QObject::connect(rotateButton, &QPushButton::clicked, [&]() {
        // Get rotate angles from user
        bool ok;
        float alpha = QInputDialog::getDouble(nullptr, "Rotation angles", "Alpha:", 0, -360, 360, 2, &ok);  // Alpha
        if (!ok) return;

        float beta = QInputDialog::getDouble(nullptr, "Rotation angles", "Beta:", 0, -360, 360, 2, &ok);  // Beta
        if (!ok) return;

        float gamma = QInputDialog::getDouble(nullptr, "Rotation angles", "Gamma:", 0, -360, 360, 2, &ok);  // Gamma
        if (!ok) return;

        // Get extra parameters
        float z0 = QInputDialog::getDouble(nullptr, "Projection parameters", "z0:", 0, -1e9, 1e9, 2, &ok);
        if (!ok) return;

        float d = QInputDialog::getDouble(nullptr, "Projection parameters", "d:", 100, 0, 1e9, 2, &ok);
        if (!ok) return;

        // Rotate points
        QMatrix4x4 rotation;
        rotation.rotate(alpha, 1.0, 0.0, 0.0);
        rotation.rotate(beta, 0.0, 1.0, 0.0);
        rotation.rotate(gamma, 0.0, 0.0, 1.0);
        for (QVector3D &point : points) {
            point = rotation.map(point);
        }

        // Projection to 2D points
        QVector<QPointF> leftPoints;
        QVector<QPointF> rightPoints;
        for (const QVector3D &point : points) {
            float x = point.x() * d / (d - point.z() + z0);
            float y = point.y() * d / (d - point.z() + z0);
            if (point.z() + z0 > 0) {
                rightPoints.append(QPointF(x, y));
            } else {
                leftPoints.append(QPointF(x, y));
            }
        }

        scene.clear();

        // Drawing the points of the left subset
        int scale = 100;

        for (const QPointF &point : leftPoints) {
            QGraphicsEllipseItem *item = new QGraphicsEllipseItem(point.x() * scale, point.y() * scale, 4, 4);
            item->setBrush(QBrush(Qt::cyan));
            scene.addItem(item);
        }

        // Drawing the points of the right subset
        for (const QPointF &point : rightPoints) {
            QGraphicsEllipseItem *item = new QGraphicsEllipseItem(point.x() * scale, point.y() * scale, 4, 4);
            item->setBrush(QBrush(Qt::red));
            scene.addItem(item);
        }

        view.update();
    });
    */

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &view, [&] {
        // Get rotate angles from user
        float alpha = 0.5;
        float beta = 0.5;
        float gamma = 0.5;

        // Get extra parameters
        float z0 = 0.0;
        float d = 100;

        // Rotate points
        QMatrix4x4 rotation;
        rotation.rotate(alpha, 1.0, 0.0, 0.0);
        rotation.rotate(beta, 0.0, 1.0, 0.0);
        rotation.rotate(gamma, 0.0, 0.0, 1.0);
        for (QVector3D &point : points) {
            point = rotation.map(point);
        }

        // Projection to 2D points
        QVector<QPointF> leftPoints;
        QVector<QPointF> rightPoints;
        for (const QVector3D &point : points) {
            float x = point.x() * d / (d - point.z() + z0);
            float y = point.y() * d / (d - point.z() + z0);
            if (point.z() + z0 > 0) {
                rightPoints.append(QPointF(x, y));
            } else {
                leftPoints.append(QPointF(x, y));
            }
        }

        // Clear scene before draw
        scene.clear();

        // Drawing the points of the left subset
        int scale = 80;
        for (const QPointF &point : leftPoints) {
            QGraphicsEllipseItem *item = new QGraphicsEllipseItem((point.x() * scale) + WIDTH / 2, (point.y() * scale) + HEIGHT / 2, 4, 4);
            item->setBrush(QBrush(Qt::cyan));
            scene.addItem(item);
        }

        // Drawing the points of the right subset
        for (const QPointF &point : rightPoints) {
            QGraphicsEllipseItem *item = new QGraphicsEllipseItem((point.x() * scale) + WIDTH / 2, (point.y() * scale) + HEIGHT / 2, 4, 4);
            item->setBrush(QBrush(Qt::red));
            scene.addItem(item);
        }

        view.update();
    });

    timer.start(1000 / 60); // 60 FPS

    // scene.addWidget(rotateButton);

    view.show();
    return a.exec();
}
