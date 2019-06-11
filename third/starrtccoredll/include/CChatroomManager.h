#pragma once
#include "IChatroomManagerListener.h"
#include "IStarIMChatroomListener.h"
#include "IChatroomGetListListener.h"
#include "CUserManager.h"
#include <list>
#include "ChatroomInfo.h"
#include <string>
#include "CChatroomType.h"
using namespace std;

/*
 *�����ҹ�����
 */
class CChatroomManager : public IStarIMChatroomListener
{
public:
	/*
	 * ���캯��
	 * @param pUserManager �û���Ϣ
	 * @param pChatroomManagerListener �ص�����ָ��
	 */
	CChatroomManager(CUserManager* pUserManager, IChatroomManagerListener* pChatroomManagerListener);
	/*
	 * ��������
	 */
	~CChatroomManager();
public:
	/*
	 * ���ӻ�ȡ�б���ص�����ָ��
	 * @param pChatroomGetListListener �ص�����ָ��
	 */
	static void addChatroomGetListListener(IChatroomGetListListener* pChatroomGetListListener);
	
	/*
	 * ��ȡ�������б�
	 * @param pUserManager �û���Ϣ
	 * @param listType ����
	 */
	static void getChatroomList(CUserManager* pUserManager, string strUserId, int listType);

	/*
	 * ���÷���ֵ
	 */
	void resetReturnVal();

	/*
	 * ����chatroom id
	 * @param chatRoomId chatroom id
	 */
	void setChatroomId(string chatRoomId);

	/*
	 * ͨ�����Ȼ�ȡChatRoom�����ַ
	 */
	bool getChatRoomServerAddr();

	/*
	 * ����ChatRoom
	 * @param strName ����
	 * @param chatroomType ����
	 */
	bool createChatRoom(string strName, int chatroomType);

	/*
	 * ����ChatRoom
	 */
	bool joinChatRoom(string strChatroomId);
	/*
	 * ��ѯchatroom��������
	 */
	bool getOnlineNumber(string strChatroomId);

	bool banToSendMsg(string banUserId, int banTime);
	bool kickOutUser(string kickOutUserId);

	/*
	 * ������Ϣ
	 * @param pIMMessage ��Ϣ����
	 */
	CIMMessage* sendChat(string strMsg);

	/*
	 * ����˽��
	 * @param toUserId �Է�userId
	 * @param msgData ��Ϣ����
	 */
	CIMMessage* sendPrivateChat(string toUserId, string msgData);

	/*
	 * ���Ϳ�����Ϣ
	 * @param targetId �Է�targetId
	 * @param code ��Ϣ����
	 */
	bool sendChatroomPrivateControlMessage(string targetId, int code);

	/*
	 * ɾ��������
	 */
	bool deleteChatRoom(string strRoomId, int listType);

	/*
	 * �������ϱ���������������Ϣ
	 */
	bool reportChatroom(string strRoomId, int listType, string data);

	/**
	 * �˳�������
	 * @param strChatroomId Ҫ�˳���������ID
	 */
	bool exitChatroom(string strChatroomId);

	/*
	 *  �˳�
	 */
	bool exit();

public:
	/**
	 * �����Ҵ����ɹ�
	 */
	virtual void chatroomCreateOK(string roomId, int maxContentLen);

	/**
	 * �����Ҽ���ɹ�
	 */
	virtual void chatroomJoinOK(string roomId, int maxContentLen);

	/**
	 * �����Ҵ���ʧ��
	 */
	virtual void chatroomCreateFailed(string errString);

	/**
	 * �����Ҽ���ʧ��
	 */
	virtual void chatroomJoinFailed(string roomId, string errString);

	/**
	 * �����ұ���
	 */
	virtual void chatRoomErr(string errString);

	/**
	 * �����ҹرճɹ�
	 */
	virtual void chatroomStopOK();

	/**
	 * ��ѯ�������б��ص�
	 */
	virtual int chatroomQueryAllListOK(list<ChatroomInfo>& chatRoomInfoList);

	/**
	 * ������ɾ���ɹ�
	 */
	virtual void chatroomDeleteOK(string roomId);

	/**
	 * ������ɾ��ʧ��
	 */
	virtual void chatroomDeleteFailed(string roomId, string errString);

	/**
	 * �����ҽ��Գɹ�
	 */
	virtual void chatroomBanToSendMsgOK(string banUserId, int banTime);

	/**
	 * �����ҽ���ʧ��
	 */
	virtual void chatroomBanToSendMsgFailed(string banUserId, int banTime, string errString);

	/**
	 * ���������˳ɹ�
	 */
	virtual void chatroomKickOutOK(string kickOutUserId);

	/**
	 * ��������
	 */
	virtual void chatroomSendMsgNoFee();

	/**
	 * ����������ʧ��
	 */
	virtual void chatroomKickOutFailed(string kickOutUserId, string errString);

	/**
	 * ������ �Լ�������
	 */
	virtual void chatroomSendMsgBanned(int remainTimeSec);

	/**
	 * ������ �Լ����߳�
	 */
	virtual void chatroomKickedOut();

	/**
	 * ������ �յ���Ϣ
	 */
	virtual void chatroomGetNewMsg(CIMMessage* pMsg);

	/**
	 * ������ �յ�˽����Ϣ
	 */
	virtual void chatroomGetNewPrivateMsg(CIMMessage* pMsg);

	/**
	 * ��������������
	 */
	virtual void getRoomOnlineNumber(string roomId, int number);

	/**
	 * ��������������
	 */
	virtual void sendMessageSuccess(int msgIndx);

	/**
	 * ��������������
	 */
	virtual void sendMessageFailed(int msgIndx);

	/**
	 * �յ�������Ϣ
	 */
	virtual void revControlMessage(string fromID, int code);

	/**
	 * �ɹ�
	 * @param data
	 */
	virtual void success();

	/**
	 * ʧ��
	 * @param errMsg
	 */
	virtual void failed(string errMsg);

	/**
	 * ��ȡ��ǰChatroom id
	 * @return Chatroom id
	 */
	string getChatroomId();
private:
	//�û���Ϣ
	CUserManager* m_pUserManager;
	//�ص�����ָ��
	IChatroomManagerListener* m_pChatroomManagerListener;
	//��ȡ�б��ص�����ָ��
	static IChatroomGetListListener* m_pChatroomGetListListener;
	//������Ip
	string m_strChatRoomServerIp;
	//�������˿ں�
	int m_nChatRoomServerPort;
	bool m_bJoinChatRoom;
	bool m_bReturn;
	bool m_bSuccess;
	string m_strErrInfo;
	string m_ChatRoomId;
};
