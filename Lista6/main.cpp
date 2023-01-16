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

float to2dPoint(float xy, float z, float z0, float d);

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

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &view, [&] {
        // Get rotate angles from user
        float alpha = 0.5;
        float beta = 0.5;
        float gamma = 0.5;

        // Get extra parameters
        float z0 = 100;
        float d = 1;

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
            float x = point.x();
            float y = point.y();
            float z = point.z();

            float xLeft = to2dPoint(x, z, z0, d);
            float yLeft = to2dPoint(y, z, z0, d);
            float xRight = to2dPoint(x, z, z0, -d);
            float yRight = to2dPoint(y, z, z0, -d);
            rightPoints.append(QPointF(xLeft, yLeft));
            leftPoints.append(QPointF(xRight, yRight));
        }

        // Clear scene before draw
        scene.clear();

        // Drawing the points of the left subset
        int scale = 10000;
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

float to2dPoint(float xy, float z, float z0, float d) {
    return xy * d / (d - z + z0);
}
