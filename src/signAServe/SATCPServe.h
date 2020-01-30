#ifndef SAXMLRPCSERVE_H
#define SAXMLRPCSERVE_H
#include <QObject>
#include "SAAbstractServe.h"
#include "SAServeGlobal.h"
class SATCPServePrivate;

/**
 * @brief The SATCPServe class tcp/ip服务的封装，对应多进程通信
 *
 * 协议约定：
 * - 首先客户端必须和服务端进行连接并分配token，后续token是所有交互的关键，如果token失效需要从新建立注册
 * - 本类每对应一个token会创建一个线程进行处理
 */
class SASERVE_EXPORT SATCPServe : public QObject,SAAbstractServe
{
    Q_OBJECT
    SA_IMPL(SATCPServe)
public:
    SATCPServe(QObject* par = nullptr);
    virtual ~SATCPServe();
    //监听
    virtual bool listen(int port,const QHostAddress &address = QHostAddress::Any);
    //关闭
    virtual void close();
    //
    virtual bool hasPendingConnections() const;
    //
    virtual QAbstractSocket *nextPendingConnection();
    //获取所有的连接
    QList<QAbstractSocket*> getAllConnection() const;
signals:
    /**
     * @brief acceptError 等同QTcpServer::acceptError
     * @param socketError
     */
    void acceptError(QAbstractSocket::SocketError socketError);
    /**
     * @brief 等同 QTcpServer::newConnection()
     */
    void newConnection();

private slots:
    void onNewConnection();
private:
    void _init();
};

#endif // SAXMLRPCSERVE_H
