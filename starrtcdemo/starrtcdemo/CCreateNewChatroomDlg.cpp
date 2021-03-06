// CCreateNewChatroomDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CCreateNewChatroomDlg.h"
#include "afxdialogex.h"


// CCreateNewChatroomDlg 对话框

IMPLEMENT_DYNAMIC(CCreateNewChatroomDlg, CDialogEx)

CCreateNewChatroomDlg::CCreateNewChatroomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CREATE_NEW_CHATROOM, pParent)
{
	m_strRoomName = "";
}

CCreateNewChatroomDlg::~CCreateNewChatroomDlg()
{
}

void CCreateNewChatroomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NEW_CHATROOM_NAME, m_editName);
}


BEGIN_MESSAGE_MAP(CCreateNewChatroomDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_NEW_CHATROOM, &CCreateNewChatroomDlg::OnBnClickedButtonCreateNewChatroom)
END_MESSAGE_MAP()


// CCreateNewChatroomDlg 消息处理程序


void CCreateNewChatroomDlg::OnBnClickedButtonCreateNewChatroom()
{
	m_editName.GetWindowText(m_strRoomName);
	if (m_strRoomName == "")
	{
		AfxMessageBox("请输聊天室名称");
	}
	OnOK();
}
