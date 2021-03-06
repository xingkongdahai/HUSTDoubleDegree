/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Prior_Thr.cpp
//This function is to find the prior element in the gived BiTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef enum{Link,Thread} PointerTag;
typedef char TElemType;

typedef struct BiThrNode		//define structure BiTree
{  
	TElemType data; // 数据域
    struct BiThrNode *lchild,*rchild; // 左右孩子
    PointerTag ltag,rtag; // 左右标志位
}BiThrNode, *BiThrTree;

/* 递归创建二叉树 */
int CreateBiThrTree(BiThrTree &T,char array[],int &i)	//sub-function
{  
	TElemType ch;
    //cout<<"Pleae input data (/ for NULL node!) : ";
    //cin>>ch;
    ch=array[i];
    cout<<ch<<"  ";
    i++;
    if(ch=='/')  T=NULL;
    else
    {  
		if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode))))
		{  
			cout<<"Overflow!";			//no alloction
	        return (ERROR);
		}
        T->data=ch;
        CreateBiThrTree(T->lchild,array,i);	//create lchild
        CreateBiThrTree(T->rchild,array,i); //create rchild
    }
    return (OK);
} //CreateBiTree() end

/* 代码有误，具体查看 Next_Thr.CPP */
void InThreading(BiThrTree p,BiThrTree &pre)	//InThreading() sub-function
{   
	if(p)
    {  
		InThreading(p->lchild,pre);		//InThreading lchild
        if(!p->lchild)
        {  
			/* 原代码有误 */
			//p->ltag=Link;
			p->ltag=Thread;
			p->lchild=pre;
        }
        if(!pre->rchild)
        {  
			pre->rtag=Thread;
	        pre->rchild=p;
        }
        pre=p;
        InThreading(p->rchild,pre);			//InThreading rchild
    }
} //InThreading() end

int InOrderThreading(BiThrTree &Thrt,BiThrTree T)	//sub-function
{   
	BiThrTree pre;
    Thrt=(BiThrTree)malloc(sizeof(BiThrTree));	//allocate memory
    if(!Thrt)
    {   
		cout<<endl<<"Overflow!";
	    return (ERROR);
    }
    Thrt->ltag=Link;
    Thrt->rtag=Thread;
    Thrt->rchild=Thrt;
    if(!T)
		Thrt->lchild=Thrt;
    else
    {  
		Thrt->lchild=T;
	    pre=Thrt;
	    InThreading(T,pre);		//call InThreading()
	    pre->rchild=Thrt;
	    pre->rtag=Thread;
	    Thrt->rchild=pre;
    }
    return (OK);
} //InOrderThreadng() end

int Prior_Thr(BiThrTree t,BiThrTree Thrt,BiThrTree &p)	//sub-function
{  
	p=t->lchild; // 该t结点左指针域
    if(p==Thrt)
    {  
		cout<<endl<<"Error!";
        return (ERROR);
    }
    if(t->ltag==Link) // 如果为线索
    {  
		while(p->rtag==Link) // p结点右指针域为右孩子
		{
			cout<<endl<<"p->prior="<<p->data;
			p=p->rchild; // p等于右孩子
		}
    }
    return (OK);
} //Prior_Thr() end

void main()			//main() function
{  
	BiThrTree Thrt,T;
    char array[]={'A','B','C','/','/','D','/','/','E','/','/'};
    int i=0;
    cout<<endl<<"Create BiTree as follows:"<<endl;
    CreateBiThrTree(T,array,i);	//call CreateBiTree()
    //getch();
    if(InOrderThreading(Thrt,T))
		cout<<endl<<"InOrderThreading Success !";
    BiThrTree p;
    p=Thrt->lchild->lchild->rchild;	//initial p
    cout<<endl<<"p->data="<<p->data;
    Prior_Thr(T,Thrt,p);			//call Prior_Thr()
    cout<<endl<<"p->prior="<<p->data;
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end