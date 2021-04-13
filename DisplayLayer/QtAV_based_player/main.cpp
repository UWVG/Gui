#include <QApplication>
#include <QtAV>
#include <QtAVWidgets>
#include <QDebug>

int main(int argc, char *argv[])
{
    QString url;
    if (argc != 2){
        url = "rtmp://58.200.131.2:1935/livetv/cctv1hd";
        qDebug() << "default url:" << url;
    }
    else{
        url = *(argv + 1);
        qDebug() << "url:" << url;
    }

    QApplication a(argc, argv);

    QStringList priorityList;
    priorityList << "CUDA" << "FFmpeg";
    QtAV::WidgetRenderer renderer;
    // renderer.setWindowTitle(url);
    renderer.setWindowFlags(Qt::FramelessWindowHint);
    renderer.show();
    QtAV::AVPlayer player;
    player.setRenderer(&renderer);
    player.setVideoDecoderPriority(priorityList);
    player.setBufferMode(QtAV::BufferBytes);
    player.setBufferValue(1000);
    player.play(url);

    return a.exec();
}
