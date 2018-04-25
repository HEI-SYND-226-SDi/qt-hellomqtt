#include <QtCore>
#include <QtMqtt>

int main(int argc, char** argv) {
    QCoreApplication application(argc, argv);

    QMqttClient client;
    client.setHostname("vlesdi.hevs.ch");
    client.setPort(1883);
    client.setCleanSession(true);
    client.setUsername("sdiXX");
    client.setPassword(QCryptographicHash::hash("sdiXX", QCryptographicHash::Md5).toHex());
    client.setWillTopic("sdiXX/hello/status");
    client.setWillMessage("offline");
    client.setWillRetain(true);
    client.connectToHost();

    QObject::connect(&client, &QMqttClient::connected, [&]() {
        client.publish(QMqttTopicName("sdiXX/hello/status"), "online", 0, true);
        client.subscribe(QMqttTopicFilter("sdiXX/hello/text"));
    });

    QObject::connect(&client, &QMqttClient::messageReceived, [&](const QByteArray& message, const QMqttTopicName& topic) {
        qDebug() << "Received message:" << topic.name();
        qDebug() << message;
        client.publish(QMqttTopicName("sdiXX/hello/TEXT"), message.toUpper());
    });

    return application.exec();
}
