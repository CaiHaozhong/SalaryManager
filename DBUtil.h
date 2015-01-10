#pragma once
#include <string>
using namespace std;

class DBUtil{

private:
	sqlite3 *pDB;//���ݿ�ָ��
	char * errMsg;//������Ϣ
	std::string sqlstr;//SQLָ��

	int result;//sqlite3_exec����ֵ

	static DBUtil* instance;

    DBUtil():pDB(NULL),errMsg(NULL){}
public:
    
	
	static DBUtil* getInstance();
    /************************************************************
            ��װ sqlite3����
     ************************************************************/
    //��������һ��db���ݿ� dbΪ���ݿ������
    //  �����ݿ�
     bool initDB(const char *db);
    
    //�����жϱ���Ƿ����
    // name:��ʾ����
     bool tableIsExist(string name);
    
    
    //��������һ������Ϊname�ı�񣬴���ʱ����ƥ��ʱ���иñ�Ĵ�����������򲻴���
    //������
     bool createTable(string sql,string name);
    
    //����ɾ��һ�ű���Ϊname�ı��ɾ��ʱ����ƥ���Ƿ��иñ�Ĵ��������������ִ��ɾ������
    //ɾ������
     bool deleteTable(string sql,string name);
    
    //��������в���һ������
    //����һ������
     bool insertData(string sql);
    
    //���������ɾ��һ������
    //ɾ��һ������
     bool deleteData(string sql);
    
    //����������޸�һ������
    // �޸�һ������
     bool updateData(string sql);
    
    //��ȡһ����¼������
    // ��ü�¼������
     int getDataCount(string sql);
    
    //��ȡһ����¼����Ϣ
    /*
     *  �˷����ǲ�ѯ����,�൱֮��Ҫ,pSender����Ǹ�vector
     */
     void getDataInfo(string sql,bool *pSend);
    
    //�رմ򿪵����ݿ�
     void closeDB();

};
