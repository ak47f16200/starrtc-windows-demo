#pragma once
#include "CMinClassDataShowView.h"
#include "CUserManager.h"
#include "XHLiveManager.h"
#include "CSoundManager.h"
#include "CLiveProgram.h"
#include "CDataControl.h"
#include "CWhitePanelDlg.h"
#include "CConfigManager.h"
// CMinClassDlg 对话框

class CMinClassDlg : public CDialogEx, public CLocalDataControl, public ILiveManagerListener, public ISoundCallback, public IWhitePanelCallback
{
	DECLARE_DYNAMIC(CMinClassDlg)

public:
	CMinClassDlg(CUserManager* pUserManager, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMinClassDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MIN_CLASS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonMinClassSendMsg();
	afx_msg void OnBnClickedButtonMinClassClear();
	afx_msg void OnBnClickedButtonMinClassRevoke();
	afx_msg void OnBnClickedButtonMinClassSetColor();
	afx_msg void OnBnClickedButtonMinClassStyle();
	afx_msg void OnBnClickedButtonMinClassApplyUpload();
	afx_msg void OnBnClickedButtonMinClassExitUpload();
	afx_msg LRESULT OnRecvMinClassMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRecvWhitePanelMsg(WPARAM wParam, LPARAM lParam);
public:
	// start回调函数
	/**
	 * 有主播加入
	 * @param liveID 直播ID
	 * @param actorID 新加入的主播ID
	 */
	virtual void onActorJoined(string liveID, string actorID);

	/**
	 * 有主播离开
	 * @param liveID 直播ID
	 * @param actorID 离开的主播ID
	 */
	virtual void onActorLeft(string liveID, string actorID);

	/**
	 * 房主收到其他用户的连麦申请
	 * @param liveID
	 * @param applyUserID
	 */
	virtual void onApplyBroadcast(string liveID, string applyUserID);

	/**
	 * 申请连麦用户收到的回复
	 * @param liveID
	 * @param result
	 */
	virtual void onApplyResponsed(string liveID, bool bAgree);

	/**
	* 普通用户收到连麦邀请
	* @param liveID 直播ID
	* @param applyUserID 发出邀请的人的ID（主播ID）
	*/
	virtual void onInviteBroadcast(string liveID, string applyUserID);

	/**
	 * 主播收到的邀请连麦结果
	 * @param liveID 直播ID
	 * @param result 邀请结果
	 */
	virtual void onInviteResponsed(string liveID);

	/**
	 * 一些异常情况引起的出错，请在收到该回调后主动断开直播
	 * @param liveID 直播ID
	 * @param error 错误信息
	 */
	virtual void onLiveError(string liveID, string error);

	/**
	 * 聊天室成员数变化
	 * @param number
	 */
	virtual void onMembersUpdated(int number);

	/**
	 * 自己被踢出聊天室
	 */
	virtual void onSelfKicked();

	/**
	 * 自己被踢出聊天室
	 */
	virtual void onSelfMuted(int seconds);

	/**
	 * 连麦者的连麦被强制停止
	 * @param liveID 直播ID
	 */
	virtual void onCommandToStopPlay(string  liveID);

	/**
	 * 收到消息
	 * @param message
	 */
	virtual void onReceivedMessage(CIMMessage* pMessage);

	/**
	 * 收到私信消息
	 * @param message
	 */
	virtual void onReceivePrivateMessage(CIMMessage* pMessage);

	virtual int getRealtimeData(string strUserId, uint8_t* data, int len);
	virtual int getVideoRaw(string strUserId, int w, int h, uint8_t* videoData, int videoDataLen);
public:
	virtual void addUpId();
	virtual void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	virtual int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);
	virtual void drawPic(YUV_TYPE type, int w, int h, uint8_t* videoData, int videoDataLen);
public:
	virtual void getLocalSoundData(char* pData, int nLength);
	virtual void querySoundData(char** pData, int* nLength);
public:
	virtual void actionCallback(WHITE_PANEL_ACTION type, CScreenPoint& point, int lineColor);
public:
	void stopMinClass();
	bool watchMinClass();
	bool startMinClass();
	bool createMinClass(string strName);
	void setConfig(CConfigManager* pConfig);
public:
	CStatic m_LiveArea;
	CListBox m_HistoryMsg;
	CEdit m_SendMsg;

	bool m_bWatch;

	CListBox m_liveList;
	CMinClassDataShowView* m_pDataShowView;
	CUserManager* m_pUserManager;
	CConfigManager* m_pConfig;

	XHLiveManager* m_pLiveManager;
	CSoundManager* m_pSoundManager;
	CLiveProgram* m_pCurrentLive;
	HANDLE m_hSetShowPicThread;
	HANDLE m_hSetShowPicEvent;
	CStatic m_MinClassName;
	CStatic m_WhitePanelArea;
	CWhitePanelDlg m_WhitePanelDlg;
	afx_msg void OnMove(int x, int y);
	
};
