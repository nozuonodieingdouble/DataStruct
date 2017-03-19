#include <iostream>

/*����˫�ױ�ʾ�����ṹ����  */
#define MAXSIZE 100
typedef int ElemType;       //�������������ͣ��ݶ�Ϊ����   
typedef struct PTNode       //���ṹ  
{
     ElemType data;          //�������  
     int parent;             //˫��λ��  
 }PTNode;

 typedef struct
 {
     PTNode nodes[MAXSIZE];  //�������  
     int r, n;                //����λ�úͽ����  
}PTree;



 /*���ĺ��ӱ�ʾ�����ṹ����  */
 #define MAXSIZE 100
 typedef int ElemType;       //�������������ͣ��ݶ�Ϊ����   
 typedef struct CTNode       //���ӽ��  
 {
     int child;
     struct CTNode *next;
 }*ChildPtr;
 
 typedef struct              //��ͷ�ṹ  
 {
     ElemType data;
     ChildPtr firstchild;
 }CTBox;
 typedef struct              //���ṹ  
 {
     CTBox nodes[MAXSIZE];   //�������  
     int r, n;                //������λ�úͽ����  
 }CTree;


 /*���ĺ����ֵܱ�ʾ���ṹ���� */
 typedef struct CSNode
{
     ElemType  data;
     struct CSNode  *firstchild, *rightsib;
 }CSNode, *CSTree;




