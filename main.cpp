#include <QCoreApplication>
#include <QProcess>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

    QProcess *process = new QProcess();
    process->start("/bin/zsh", QStringList() << "-c" << "ls -l /Applications");
    process->waitForReadyRead();
    QString str = QString(process->readAll());
    out << str << Qt::endl;
    process->waitForFinished();
    out << "Process finished with exit code " << process->exitCode() << " and exit status " << process->exitStatus() << Qt::endl;

    return a.exec();
}
