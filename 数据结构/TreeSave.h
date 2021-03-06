#include <iostream>

/*树的双亲表示法结点结构定义  */
#define MAXSIZE 100
typedef int ElemType;       //树结点的数据类型，暂定为整形   
typedef struct PTNode       //结点结构  
{
     ElemType data;          //结点数据  
     int parent;             //双亲位置  
 }PTNode;

 typedef struct
 {
     PTNode nodes[MAXSIZE];  //结点数组  
     int r, n;                //根的位置和结点数  
}PTree;



 /*树的孩子表示法结点结构定义  */
 #define MAXSIZE 100
 typedef int ElemType;       //树结点的数据类型，暂定为整形   
 typedef struct CTNode       //孩子结点  
 {
     int child;
     struct CTNode *next;
 }*ChildPtr;
 
 typedef struct              //表头结构  
 {
     ElemType data;
     ChildPtr firstchild;
 }CTBox;
 typedef struct              //树结构  
 {
     CTBox nodes[MAXSIZE];   //结点数组  
     int r, n;                //根结点的位置和结点数  
 }CTree;


 /*树的孩子兄弟表示法结构定义 */
 typedef struct CSNode
{
     ElemType  data;
     struct CSNode  *firstchild, *rightsib;
 }CSNode, *CSTree;




