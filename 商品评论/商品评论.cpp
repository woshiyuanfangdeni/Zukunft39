/*商品评价界面*/
/*你的商品评论*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <windows.h>
struct comments{//结构体 
	int num;
	char type[50];
	char judgeMent[20];	
	char name[100];	
	char com[200];
	char attitude;
	int timeWait ;
	char yourJudgeMent[200]; 	
};
struct comments com[] = {//结构体的内容 
	{10001,"香辣鸡腿堡","★★★★★","肯德基老爷爷","Oh，Honey mom！",'Y',28},
	{10002,"炸鸡翅","★★★★☆","厉不厉害你坤哥","你干嘛~哎呦，真好吃",'Y',17},
	{10003,"薯条","★★★☆☆","W","薯条很大，埋下去能吓他们一跳",'Y',10},
	{10004,"牛肉堡","★☆☆☆☆","敬汉卿","牛肉质感很硬！运送时间太长了，不是很好吃",'N',43},	
	{10005,"可乐","★★★★★","土间埋","嗯~可乐好好喝",'Y',19},
	{10006,"香芋丸","★★★★☆","矮人王","什么？我们这个不是饼干，我们的这个丸子是......",'Y',25}	
};
int comment(void)//打印商品评价 
{
	struct comments *p;
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|用户编码\t          商品名称\t\t\t商品评价\t\t   昵称\t\t\t        买家评论\t\t                           是否好评(Y/N)  等待时间/min|\n");
	for(p = com;p<com+6;p++)
	{
		printf("|%-5d  \t\t  %-20s\t\t%-20s       %-20s         %-50s  %-5c         %-6d      |\n",p->num,p->type,p->judgeMent,p->name,p->com,p->attitude,p->timeWait);
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
} 
int commentAndYours(char judgeMentByStarByChar[],char yourJudgeMent[],char yesOrNotByChar)//打印商品与你自己的评论 
{
	int i = 10006;
	int timeRand = 0; 
	struct comments *p;
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|用户编码\t          商品名称\t\t\t商品评价\t\t   昵称\t\t\t        买家评论\t\t                           是否好评(Y/N)  等待时间/min|\n");
	for(p = com;p<com+6;p++)
	{
		printf("|%-5d  \t\t  %-20s\t\t%-20s       %-20s         %-50s  %-5c         %-6d      |\n",p->num,p->type,p->judgeMent,p->name,p->com,p->attitude,p->timeWait);
	}
	srand((unsigned int)time(NULL));
	while(timeRand != 1)
	{
		if(timeRand<40&&timeRand>20) break;
		else timeRand = rand();
	}
	p->num = i + 1 ; 
	strcpy(p->type,"你购买的商品");		
 	strcpy(p->judgeMent,judgeMentByStarByChar); 
 	strcpy(p->name,"我");
 	strcpy(p->com,yourJudgeMent);//p->com = yourJudgeMent;
 	p->attitude = yesOrNotByChar;
 	p->timeWait =  timeRand;
	printf("|%-5d  \t\t  %-20s\t\t%-20s       %-20s         %-50s  %-5c         %-6d      |\n",p->num,p->type,p->judgeMent,p->name,p->com,p->attitude,p->timeWait); 
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
} 
void humanTest()//输入验证码检验你是不是人机 
{
	int randNum = 0;
	int enterNum = 0;
	srand((unsigned int)time(NULL));
	while(randNum != 1)
	{
		if(randNum<=9999&&randNum>=1000) break;
		else randNum = rand();
	}
	printf("为了判断您的身份，请您输入右侧的验证码:%d\n",randNum);
	scanf("%d",&enterNum);
	while(enterNum != randNum)
	{
		printf("您的验证码错误！请重新输入：");
		scanf("%d",&enterNum); 
	}
	printf("验证成功~ >W< ");	
}
void errorYesOrNot()//判断您是否查看了评论界面 （这里为否） 
{
	printf("已取消查看相关内容\n\n");
} 
void remainComment()//判断您是否查看了评论界面（这里为是） 
{
	comment();
}
void clearScreen()//在再次查看评论时清屏查看 
{
	system("cls");
}
void loadYourComment(char arr[])//加载你的评论 
{	
	char loadScene[8] = "\0";
	for(int i = 0;i<7;i++)
	{
		loadScene[i] = arr[i]; 
		printf("正在上传中%s\n",loadScene);
		Sleep(1000);
	}
	printf("上传成功！\n");
	humanTest(); 
} 
void writeComment()//打印账单时加上你的评论 
{
	printf("请再次输入您的评论以便于我们更好的记录下来 >W< (该评价仅放在您的账单打印出来)\n");
	char loadScene[8] = " ......";
	char ch[200];
	FILE*fp;
	fp = fopen("您的账单", "w");
 	if(fp==NULL)
	{
		perror("您的账单");
		return;
	}
	scanf("%s",ch);   
	fprintf(fp,"%s",ch);	
	fclose(fp);
	fp=NULL;	 
	loadYourComment(loadScene); //加载评论上传界面 	
}
int readComment()//读取你账单上的评论 
{
	char str[200];
	FILE*fp;
	fp = fopen("您的账单", "r"); 
	if(fp==NULL)
	{
		perror("您的账单");
		return 1;
	}
	fgets(str,200,fp);
	printf("%s",str);	
	fclose(fp);
	fp=NULL;	
} 
int main(void)//评论界面主函数 
{
	int yesOrNot;
	char yesOrNotByChar; 
	int judgeMentByStar = 0; 
	char judgeMentByStarByChar[20] = "\0"; 
	char yourJudgeMent[200];
	char loadScene[8] = " ......";
	char judgeMentStar1[20] = "★☆☆☆☆";
	char judgeMentStar2[20] = "★★☆☆☆";
	char judgeMentStar3[20] = "★★★☆☆";
	char judgeMentStar4[20] = "★★★★☆";
	char judgeMentStar5[20] = "★★★★★";
	
	
	struct comments *pJudge;
	
		
	printf("是否查看关于该店铺的有关评论？（按1表示确认，按0表示取消）\n");//显示评论界面 
	scanf("%d",&yesOrNot);
	while (yesOrNot!=65500) 
	{
		switch (yesOrNot)
		{
			case 0:errorYesOrNot();
			break;
			case 1:comment();
			printf("\n");
			break;
			default:printf("无此选项!\n\n"); 
			printf("是否查看关于该店铺的有关评论？（按1表示确认，按0表示取消）\n");//显示评论界面 
			scanf("%d",&yesOrNot);
			continue;	
		}	
		break;
	} 
	
		
	printf("若要取消显示请输入0清除,仍要继续显示则请输入1\n\n");//是否重新显示评论界面 
	scanf("%d",&yesOrNot);
	while(yesOrNot!=65500)
	{
		switch (yesOrNot)
		{
			case 0:clearScreen();
			break;
			case 1:clearScreen();
			remainComment();
			break; 
			default:printf("无此选项!\n\n"); 
			printf("若要取消显示请输入0清除,仍要继续显示则请输入1\n\n");
			scanf("%d",&yesOrNot);
			continue;
		}
		break;
	}
	
	
	
	printf("亲，给商品一个评价吧！(1表示好评，0表示差评)\n");//给商品好评&差评 
	printf("我的评价：");		 
	while(yesOrNot!=65500) 
	{
		scanf("%d",&yesOrNot);
		switch(yesOrNot)
		{
			case 1:printf("感谢您的好评！我们会越做越好的 >W<　～ \n\n"); 
			yesOrNotByChar = 'Y';
			break;
			case 0:printf("感谢您的评价！我们会不断改进的 QAQ　～　\n\n"); 
			yesOrNotByChar = 'N';
			break;
			default :printf("无此选项！\n\n");
			printf("我的评价：");	
			continue; 
		}		
		break;
	}
	
	
	
	printf("亲觉得您所购买的商品怎么样？给快餐打个评分吧！\n\n");//给商品评分 
	printf("您对所购买的快餐的满意程度(请在1~5分之内打分)：");	
	while(judgeMentByStar!=65500) 
	{
		scanf("%d",&judgeMentByStar); 
		switch (judgeMentByStar)
		{
			case 1:printf("\n\n%s\n\n",judgeMentStar1);
			strcpy(judgeMentByStarByChar,judgeMentStar1);
			break;
			case 2:printf("\n\n%s\n\n",judgeMentStar2);
			strcpy(judgeMentByStarByChar,judgeMentStar2);
			break;
			case 3:printf("\n\n%s\n\n",judgeMentStar3);
			strcpy(judgeMentByStarByChar,judgeMentStar3);
			break;
			case 4:printf("\n\n%s\n\n",judgeMentStar4);
			strcpy(judgeMentByStarByChar,judgeMentStar4);
			break;
			case 5:printf("\n\n%s\n\n",judgeMentStar5);
			strcpy(judgeMentByStarByChar,judgeMentStar5);
			break;
			default:printf("无此选项!\n\n"); 
			printf("您对所购买的快餐的满意程度(请在1~5分之内打分)：");
			continue;						
		}
		break;			
	}
	
	
	printf("给这个商品写一条评价吧，您的批评与建议是对我们最大的支持!\n");//记录你的评价 
	scanf("%s",yourJudgeMent); 
	
	writeComment();//写评论 
		
	
	printf("感谢您的评价！\n");//记录你的评价 
	printf("请按下1来显示所有最新的评论，按下2仅显示您的评论，按下0重新返回选择商品主界面:");//显示最新的评论&退出评论界面 
	scanf("%d",&yesOrNot);
	while(yesOrNot)
	{
		switch (yesOrNot)
		{
			case 0://返回商品选择界面 （退出评论界面） 
			break; 
			case 1: commentAndYours(judgeMentByStarByChar,yourJudgeMent,yesOrNotByChar);//显示所有评论 
			break;
			case 2: readComment();//只显示你的评论 
			break; 
			default:printf("无此选项!\n\n");
			printf("请按下1来显示所有最新的评论，按下2仅显示您的评论，按下0重新返回选择商品主界面:");
			scanf("%d",&yesOrNot);
			continue;
		}
		break;
	} 	
} 
