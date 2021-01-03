#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 66              //���鳤�ȵ����ֵ 
#define MAXVEX  20             	//��󶥵���� 
#define INFINITY 32767			//��ʾ����ֵ             	

//����ȫ�ֱ�������DFS�� 
int count1 = 0;// DFSALL ,·����������ȫ�ֱ�����ֱ��++������ֲ��������ݹ鵽��һ��ֵ����û�� 
int way1[MAXSIZE] = {0}; //·������ 
int count2 = 0;// DFSALL ,���� 
int way2[MAXSIZE] = {0}; //·������ 
int minc = MAXVEX; //��ת���ٶ�������ֵ 
int minway[MAXSIZE] = {0};//·������ 

//�������͵Ķ���
typedef struct{
    char  name[19];		//�ص������ 
	char  info[66];    //�ص�Ľ��� 
	int visited;        //���ʱ�־ 
}Vextype;

//�ڽӾ������������ 
typedef struct{
	int arcs[MAXVEX][MAXVEX]; //��(��)��Ϣ 
	Vextype vex[MAXVEX];    //������Ϣ���������͸���ʵ��������ж��� 
    int vexnum;		//������Ŀ 
	int arcnum;     //��(��)��Ŀ 
	int visited[MAXVEX];   //���ʱ�־���飬��־�Ƿ񱻷��ʹ� 
}AdjMatrix;

//�����ͼ�ļ� 
void MapFile(AdjMatrix G){
	char filename[30] = "map.txt";
	FILE *fp;
	fp = fopen(filename,"wt");
	if(fp == NULL)
	{
		printf("\n���ܴ�!");
		exit(1);
	}
   	fprintf(fp,"|------------------------------------------------------------------------------------------------|\n");
    fprintf(fp,"|                                �������ʵ��ѧУ԰�ص�һ�� ��                                   |\n");
    fprintf(fp,"|------------------------------------------------------------------------------------------------|\n");
    fprintf(fp,"|                                                                                                |\n"); 
	fprintf(fp,"|                   ��������                                                                     |\n"); 
	fprintf(fp,"|                      |                                                                         |\n");     
	fprintf(fp,"|                      |                                                                         |\n");
	fprintf(fp,"|                      |                                   ��������==================�ݷ�¥      |\n");                          
	fprintf(fp,"|                      |                                                     |         |         |\n");     
	fprintf(fp,"|            |===ˮ�����                                                    |         |         |\n"); 
	fprintf(fp,"|            |         |                                                     |         |         |\n");     
	fprintf(fp,"|           ����       |                                                     |      ������Ԣ     |\n");    
	fprintf(fp,"|          ��ѧ¥      |                                                     |         |         |\n");    
	fprintf(fp,"|            |         |                                                     |         |         |\n");  
	fprintf(fp,"|            |         |                                                     |      ���ù�Ԣ     |\n");  
	fprintf(fp,"|            |         |                                          ����Է ====|                   |\n");    
	fprintf(fp,"|            |         |                                                     |                   |\n");
	fprintf(fp,"|            |       ͼ���                                                  |                   |\n");    
	fprintf(fp,"|       ��ѧʵ��¥     |                                                     |                   |\n");     
	fprintf(fp,"|            |         |=====================================================|                   |\n");     
	fprintf(fp,"|            |         |                 |||   ������   |||                  |                   |\n");
	fprintf(fp,"|  ҽ����====|         |=====================================================|                   |\n");
	fprintf(fp,"|                      |                                                                         |\n");    
	fprintf(fp,"|                      |===������                                                                |\n");     
	fprintf(fp,"|                      |                                                                         |\n");    
	fprintf(fp,"|                      |                                                                         |\n");    
	fprintf(fp,"|                    ����Է                                                                      |\n");     
	fprintf(fp,"|                      |                                                                         |\n");
    fprintf(fp,"|                      |                                                                         |\n");
	fprintf(fp,"|                  ��������¥          	                                                         |\n");      
	fprintf(fp,"|                                                                                                |\n");        
    fprintf(fp,"|------------------------------------------------------------------------------------------------|\n");
	fclose(fp);
}

//��ӡ��ͼ
void MapOutput(){
	printf("|------------------------------------------------------------------------------------------------|\n");
    printf("|                                �������ʵ��ѧУ԰�ص�һ�� ��                                   |\n");
    printf("|------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                |\n"); 
	printf("|                   ��������                                                                     |\n"); 
	printf("|                      |                                                                         |\n");     
	printf("|                      |                                                                         |\n");
	printf("|                      |                                   ��������==================�ݷ�¥      |\n");                          
	printf("|                      |                                                     |         |         |\n");     
	printf("|            |===ˮ�����                                                    |         |         |\n"); 
	printf("|            |         |                                                     |         |         |\n");     
	printf("|           ����       |                                                     |      ������Ԣ     |\n");    
	printf("|          ��ѧ¥      |                                                     |         |         |\n");    
	printf("|            |         |                                                     |         |         |\n");  
	printf("|            |         |                                                     |      ���ù�Ԣ     |\n");  
	printf("|            |         |                                          ����Է ====|                   |\n");    
	printf("|            |         |                                                     |                   |\n");
	printf("|            |       ͼ���                                                  |                   |\n");    
	printf("|       ��ѧʵ��¥     |                                                     |                   |\n");     
	printf("|            |         |=====================================================|                   |\n");     
	printf("|            |         |                 |||   ������   |||                  |                   |\n");
	printf("|  ҽ����====|         |=====================================================|                   |\n");
	printf("|                      |                                                                         |\n");    
	printf("|                      |===������                                                                |\n");     
	printf("|                      |                                                                         |\n");    
	printf("|                      |                                                                         |\n");    
	printf("|                    ����Է                                                                      |\n");     
	printf("|                      |                                                                         |\n");
    printf("|                      |                                                                         |\n");
	printf("|                  ��������¥          	                                                         |\n");      
	printf("|                                                                                                |\n");        
    printf("|------------------------------------------------------------------------------------------------|\n");    
 } 
 
//����ͼ,��Ϣ���ļ��ж�ȡ 
void Create(AdjMatrix *G){
	int i,j;
	int m,n,weight;
	int vexnum,arcnum;
	char name[19],info[66];
	
	for(i = 1; i <= G->vexnum; i++){   //��ʼ��visitedֵ���տ�ʼ��Ϊ0 
		G->vex[i].visited = 0;
    } 
    
	FILE *fp1;
	fp1 = fopen("flag.txt","rt");
	if(fp1 == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
	
	FILE *fp2;
	fp2 = fopen("introduce.txt","rt");
	if(fp2 == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
	
	FILE *fp3;
	fp3 = fopen("adj.txt","rt");
	if(fp3 == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
	
	
	fscanf(fp1,"%d %d",&vexnum,&arcnum);  //���ļ��ж���ĸ����ͱߵĸ��� 
	G->vexnum = vexnum;
	G->arcnum = arcnum;	
	
	for(i = 1; i <= G->vexnum; i++){
		fscanf(fp2,"%s\n%s",name,info);
		strcpy(G->vex[i].name,name);
		strcpy(G->vex[i].info,info);
	}
	
	for(i = 1; i <= G->vexnum; i++){ 
		for(j = 1;j <= G->vexnum; j++){ 
			G->arcs[i][j] = INFINITY;
		} 
	} 
	
	for(j = 1; j <= G->arcnum; j++){
		fscanf(fp3,"%6d %6d %6d",&m,&n,&weight);
		G->arcs[m][n] = weight;
		G->arcs[n][m] = weight;
	}
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

//��ӡ�ص��б�
void PrintPlace(AdjMatrix *G){ 
	int i;
	for(i = 1; i <= G->vexnum; i++ ){
		printf("\t\t\t\t\t\t%d\t%s\n",i,G->vex[i].name); 
    }
}


void IntroducePlace(AdjMatrix G){  
	int i, num,c;
	int flag = 1;
	char n[30];
	
	while(flag == 1 ){
		system( "cls" );
		printf( "\t\t\t\t\t\t�������������ص���Ϣ��ѯ������������\n" );
		
		printf("\t\t\t\t\t\t��ѡ����Ҫ��ѯ�ķ�ʽ\n");
		printf("\t\t\t\t\t\t1.�ص��Ų�ѯ\n"); 
		printf("\t\t\t\t\t\t2.�ص����Ʋ�ѯ\n"); 
		printf("\t\t\t\t\t\t3.�ص������ƹ�ͬ��ѯ\n"); 
		
		scanf("%d",&c);
		
		if(c == 1){
			
			system("cls");

			PrintPlace(&G);
			
			printf( "\t\t\t\t\t\t��������Ҫ���ҵĵص��ţ�" );
			scanf( "%d", &num );
			
			if(num > 0 && num <= G.vexnum ){
				printf( "\n\n");
				printf( "\t\t\t���:%d\n",num);
				printf( "\t\t\t����:%s\n", G.vex[num].name );
				printf( "\t\t\t���:%s\n\n", G.vex[num].info );
			}
			else{
				printf( "\t\t\t\t\t\t��Ϣ��������!\n" );
		    }
		    
			printf( "\n\t\t\t\t\t\t�Ƿ������ѯ�ص���Ϣ��\n" );
			printf( "\t\t\t\t\t\t1:��\n" );
			printf( "\t\t\t\t\t\t0:�����ϼ��˵�\n" );
			scanf( "%d", &flag );
		}
		else if(c == 2){
			system("cls");
			printf("\t\t\t\t\t\t��������Ҫ��ѯ�ĵص����ƣ�");
			scanf("%s",n);
			
			for(i = 1; i <= G.vexnum; i++ ){

				if(strcmp(G.vex[i].name,n) == 0){
					
					printf( "\n\n");
					printf( "\t\t\t���:%d\n",i);
					printf( "\t\t\t����:%s\n", G.vex[i].name );
					printf( "\t\t\t���:%s\n\n", G.vex[i].info );
					break;
				}
   			}

			printf( "\n\t\t\t\t\t\t�Ƿ������ѯ�ص���Ϣ��\n" );
			printf( "\t\t\t\t\t\t1:��\n" );
			printf( "\t\t\t\t\t\t0:�����ϼ��˵�\n" );
			scanf( "%d", &flag );			
		}
		else if(c == 3){
			system("cls");
			PrintPlace(&G);
			printf( "\t\t\t\t\t\t��������Ҫ���ҵĵص��ţ�" );
			scanf( "%d", &num );
			printf("\t\t\t\t\t\t��������Ҫ��ѯ�ĵص�����:");
			scanf("%s",n);
			if(num > 0 && num <= G.vexnum && strcmp(G.vex[num].name,n) == 0){
				printf( "\n\n");
				printf( "\t\t\t���:%d\n",num);
				printf( "\t\t\t����:%s\n", G.vex[num].name );
				printf( "\t\t\t���:%s\n\n", G.vex[num].info );
			}
			
			printf( "\n\t\t\t\t\t\t�Ƿ������ѯ�ص���Ϣ��\n" );
			printf( "\t\t\t\t\t\t1:��\n" );
			printf( "\t\t\t\t\t\t0:�����ϼ��˵�\n" );
			scanf( "%d", &flag );
		}
	}
	system("cls");
}

//�ص���Ϣ���ļ� 
void IntroduceFile(AdjMatrix G){
	int i;
	char filename[30] = "introduce.txt";
	
	FILE *fp;
		fp = fopen(filename,"wt");
	if(fp == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
	
	G.vexnum = 15;
	
	strcpy(G.vex[1].name,"��������"); 
	strcpy(G.vex[1].info,"�����ʵ��ѧ����У������������"); 
	strcpy(G.vex[2].name,"������"); 
	strcpy(G.vex[2].info,"���������ʵ��ѧ����У�������Ͷ���������������·����������"); 
	strcpy(G.vex[3].name,"��������"); 
	strcpy(G.vex[3].info,"�����ʵ��ѧ����У������������"); 
	strcpy(G.vex[4].name,"ˮ�����"); 
	strcpy(G.vex[4].info,"�����ʵ��ѧ����У���������ſڣ��ɸ��Ӻ���Ȫ���"); 
	strcpy(G.vex[5].name,"������ѧ¥"); 
	strcpy(G.vex[5].info,"�����ʵ��ѧ��ѧ¥����A¥��B¥���������ʵ��ѧѧ�����Ͽεĵط�");
	strcpy(G.vex[6].name,"��ѧʵ��¥"); 
	strcpy(G.vex[6].info,"�����ʵ��ѧ����У������ʵ��¥");  
	strcpy(G.vex[7].name,"�ݷ�¥"); 
	strcpy(G.vex[7].info,"�����ʵ��ѧ��ѧ¥����ѧ�����Ͽεĵط�����������·Ŷ");   
	strcpy(G.vex[8].name,"ͼ���"); 
	strcpy(G.vex[8].info,"�����ʵ��ѧͼ��ݣ����Խ����鼮����ϰ"); 
	strcpy(G.vex[9].name,"ҽ����"); 
	strcpy(G.vex[9].info,"�����ʵ��ѧҽ����"); 
	strcpy(G.vex[10].name,"����Է"); 
	strcpy(G.vex[10].info,"�����ʵ��ѧ����ʳ��");
	strcpy(G.vex[11].name,"����Է"); 
	strcpy(G.vex[11].info,"�����ʵ��ѧ����ʳ��");
	strcpy(G.vex[12].name,"������"); 
	strcpy(G.vex[12].info,"�����ʵ��ѧ�����ݣ������˶�����"); 
	strcpy(G.vex[13].name,"��������"); 
	strcpy(G.vex[13].info,"��Ϊ��˼��Ԣ�ͳ��ǹ�Ԣ"); 
	strcpy(G.vex[14].name,"������Ԣ"); 
	strcpy(G.vex[14].info,"��Ϊ������Ԣ��¥�ͱ�¥"); 
	strcpy(G.vex[15].name,"���ù�Ԣ"); 
	strcpy(G.vex[15].info,"��Ϊ���ù�Ԣ��¥�ͱ�¥");  
	
	//����Ϣ�浽�ļ���
	for(i = 1; i <= G.vexnum; i++){  
		fprintf(fp,"%s\n%s\n",G.vex[i].name,G.vex[i].info); 
	} 
	
	fclose(fp);
}

//�ڽӾ�����Ϣ���ļ� 
void AdjFile(AdjMatrix G){
	int i,j;
	char filename[30] = "adj.txt";
	char filename1[30] = "flag.txt";

	FILE *fp;
		fp = fopen(filename,"wt");
	if(fp == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
		
	FILE *fp1;
		fp1 = fopen(filename1,"wt");
	if(fp1 == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
	
	
	G.vexnum = 15;
	G.arcnum = 24;   //15�����㣬24����
	fprintf(fp1,"%d %d\n",G.vexnum,G.arcnum); //�����ļ����
		//��ʼ������ 
	for(i = 0; i <= G.vexnum; i++){   
		for(j = 0; j <= G.vexnum; j++){ 
			G.arcs[i][j] = INFINITY;  //Ȩֵȫ��������� 
		} 
	}    
	
	//���ص�����Ȩֵ������Ҫ�ߵ�·�� 
	G.arcs[1][3] = G.arcs[3][1] = 800;
	G.arcs[1][4] = G.arcs[4][1] = 120;
	G.arcs[2][3] = G.arcs[3][2] = 300;
	G.arcs[2][8] = G.arcs[8][2] = 450;
	G.arcs[2][9] = G.arcs[9][2] = 600;
	G.arcs[2][11] = G.arcs[11][2] = 100;
	G.arcs[2][12] = G.arcs[12][2] = 500;
	G.arcs[3][7] = G.arcs[7][3] = 150;
	G.arcs[4][5] = G.arcs[5][4] = 140;
	G.arcs[4][8] = G.arcs[8][4] = 200;
	G.arcs[5][6] = G.arcs[6][5] = 111;
	G.arcs[5][8] = G.arcs[8][5] = 222;
	G.arcs[6][8] = G.arcs[8][6] = 300;
	G.arcs[6][9] = G.arcs[9][6] = 417;
	G.arcs[6][10] = G.arcs[10][6] = 360;
	G.arcs[6][12] = G.arcs[12][6] = 250;
	G.arcs[7][14] = G.arcs[14][7] = 120;
	G.arcs[8][12] = G.arcs[12][8] = 345;
	G.arcs[9][10] = G.arcs[10][9] = 404;
	G.arcs[10][12] = G.arcs[12][10] = 200;
	G.arcs[10][13] = G.arcs[13][10] = 100;
	G.arcs[11][15] = G.arcs[15][11] = 150;
	G.arcs[14][15] = G.arcs[15][14] = 50;

	for(i = 1; i <= G.vexnum; ++i){
		for(j = 1; j <= G.vexnum; ++j){
			if(G.arcs[i][j] != INFINITY && i < j){
				fprintf(fp,"%10d %10d %10d\n",i,j,G.arcs[i][j]);
				}
		}
	}
	fclose(fp1);
	fclose(fp);
}

//���÷������� 
void ClearVisited(AdjMatrix *G) {
	int i;
	for(i = 0; i <= MAXVEX; i++){
		G->vex[i].visited = 0; //ȫ����0 
	}
}

//��������������� 
void DfsAll(AdjMatrix *G,int s,int e){ 
	int i,j;	
	int shuai = 0;
	G->vex[s].visited = 1;  //����ʼ��Ϊ1 
	way1[count1] = s;    //��������Ŵ���һ���������ʱcount��0 
	
	for(i = 1; i <= G->vexnum; i++){  //��������		
		if(G->arcs[s][i] != INFINITY && G->vex[i].visited == 0 && i != e){  //Ȩֵ�������������û�б����ʹ�������û�лص���� 
			count1++;  //�����±���� 
			way1[count1] = i;  //�������Ӧ���±긽�϶���ֵ 
			DfsAll(G,i,e);  //�ݹ� 
			G->vex[i].visited = 0; //�ݹ�������ص���һ�㻹ԭ��һ����״ 
			count1--;
			shuai = 0;  //�����ı�־ 
			continue;
		}
		if(G->arcs[s][i] != INFINITY && G->vex[i].visited ==0 && i == e && shuai == 0){  //��� 
			count1++;
			way1[count1] = e;
			shuai = 1;
			printf("\n");
			printf("\t%s",G->vex[way1[0]].name);  //��ʼ�� 
			for(j = 1;j <= count1; j++){
				printf("-->");
				printf("%s",G->vex[way1[j]].name);		//���δ�ӡ 
			}
			count1--;  //��ȫ�ֱ���count���0���Թ���������ʹ�� 
			return;
		}	
	}		
	return ; 
}

//���м�·���˵� 
void AllPath(AdjMatrix G,int dist[],int path[][MAXVEX]){  
	int s,e;
	int flag = 1;
	while(flag == 1){
		system("cls");
		printf( "\t\t\t\t\t\t���������������м�·����ѯ������������\n" );
		
		PrintPlace(&G);
		
		printf("\n\t\t\t\t\t���������:");
		scanf("%d",&s);
		printf("\t\t\t\t\t�����յ���:");
		scanf("%d",&e);
		
		if (s > G.vexnum || s <= 0 || e > G.vexnum || e < 0 || s == e){
			printf( "\t\t\t\t\t\t�������!\n\n" );
	    }
		else{
			ClearVisited(&G);  //����־�����ʼ�� 
			count1=0;
			printf("\n\t\t\t��%s��%s�����м�·����:\n", G.vex[s].name, G.vex[e].name);
			
			DfsAll(&G,s,e); //���ú�������ʵ�ֹ��� 
		}
		printf("\n\n\t\t\t\t\t\t�Ƿ������ѯ���м�·��?\n" );
		printf("\t\t\t\t\t\t1:��\n" );
		printf("\t\t\t\t\t\t0:�����ϼ��˵�\n" );
		scanf("%d", &flag);
	}
	system("cls");
}

//��ת���� ,Ҳ�����ù��ѣ�����A������B�����ߵ���Ŀ���ٵ�·�ߣ���A����������ȱ�������������B�Ϳ���ֹͣ�� 
void DfsLitter(AdjMatrix *G,int start,int end){
	int shuai = 0;
	int i,j;
	G->vex[start].visited = 1;
	way2[count2] = start;
	for(i = 1; i <= G->vexnum; i++){		
		if(G->arcs[start][i] != INFINITY && G->vex[i].visited == 0 && i != end){
			count2++;
			way2[count2] = i;
			DfsLitter(G,i,end); //�ݹ� 
			G->vex[i].visited = 0;
			count2--;
			shuai = 0;
			continue;
		}  //��ʱ�ѵ�������·�� 
		
		
		if(G->arcs[start][i] != INFINITY && G->vex[i].visited == 0 && i == end && shuai == 0){
			count2++;
			way2[count2] = end;
			shuai = 1;
		
			if(count2 < minc){   //���count2����󶥵���С 
				minc = count2;   //�͸�ֵ 
				for(i = 0; i <= count2; i++){
					minway[i]=way2[i];   //����¼��way2ֵ�浽minway�� 
			    }
			}
			
			count2--;
			return;
		}	
	}		
}

//��ת�������ټ�·��
void LitterPath(AdjMatrix G){
	int i,j,s,e;
	int flag = 1;
	
	while (flag == 1){
		int i;
		system("cls");
		printf("\t\t\t\t\t\t��������������ת��������·����ѯ������������\n");
		
		PrintPlace(&G);
		
		printf("\n\t\t\t\t\t���������:");
		scanf( "%d", &s);
		printf("\t\t\t\t\t�����յ���:");
		scanf("%d", &e);
		if (s > G.vexnum || s <= 0 || e > G.vexnum || e < 0 || s == e)
			printf("\t\t\t\t\t\t�������!\n\n");
	
		else{
			ClearVisited(&G);
		
			minc = MAXVEX;
			
			count2 = 0;
		
			printf("\n\t\t\t��%s��%s����ת���ټ�·��Ϊ:\n", G.vex[s].name, G.vex[e].name);
			DfsLitter(&G,s,e);  //����Ѱ�� 
		
			printf("\t\t\t%5s ",G.vex[minway[0]].name);
		
			for(i = 1; i <= minc; i++){    //mic��Ϊcount2 
				printf("-->");
				printf("%5s ",G.vex[minway[i]].name);
			}
			printf("\n\n\t\t\t\t\t\t�Ƿ������ѯ��ת���ټ�·��?\n");
			printf("\t\t\t\t\t\t1:��\n");
			printf("\t\t\t\t\t\t0:�����ϼ��˵�\n");
			scanf("%d", &flag);
			}
		system( "cls" );
	}
}

//���·��,dist�����¼�������·�����ȣ�path�����¼��Ӧ·���ϵĸ����� �������·������������ø���·�� 
void Dijkstra(AdjMatrix *G,int s,int e,int dist[MAXVEX],int path[][MAXVEX]){  
	int mindist,i,j,k,t = 1;  //mindist ·����Ȩֵ(����) 
	
	for(i = 1; i <= G->vexnum; i++){  //��dist�����ʼ���� 
		dist[i] = G->arcs[s][i]; //���ڽ�����ÿһ������Ӧ���е�ֵ����dist������ 
		
		if(G->arcs[s][i] != INFINITY){  //���Ȩֵ�������������˵����·
			path[i][1] = s;   //������¼,path[i]��¼��Դ�㵽Vi���·���ϵĸ�������
	    } 
	}	
	
	path[s][0] = 1;   //��1��־��˵��Դ��Ϊstart 
	
	for(i = 2; i <= G->vexnum; i++){   //Ѱ�Ҹ������·�� 
		
		mindist = INFINITY;  //����С��ֵ����Ϊ����� 
		
		for(j = 1; j <= G->vexnum; j++){//ѡ����СȨֵ��·�� 
		
			if(!path[j][0] && dist[j] < mindist){//jδ���뼯��S  //path�����¼ĳ�����Ƿ�ӵ�S�� 
				k = j;  //��ǰ��㵽����kȨֵ��С
				mindist = dist[j];
			}
	    }
			if(mindist == INFINITY){
				return;             //������start�����������·�� 
		    }
		    
			path[k][0] = 1;  // ������k���뵽����S�У�˵���ö����Ѿ������� 
			
			
			//����û�и�С�ģ����������޸�·�� 
			for(j = 1;j <= G->vexnum; j++){   //�޸�·��
				if(!path[j][0] && G->arcs[k][j]<INFINITY && dist[k]+G->arcs[k][j] < dist[j]){  //��k����·��δ��ѡ�й��Ķ��� &&��k����СȨֵ+k��j��Ȩֵ<��ǰ��j����СȨֵ·�� 
					dist[j] = dist[k]+G->arcs[k][j];
					t = 1;
					while(path[k][t] != 0){   //��¼���µ����·�� 
						path[j][t] = path[k][t];
						t++;
					}
					path[j][t] = k;
					path[j][t+1] = 0;
				}
			 } 	
	}
}

//��ӡ���������·��
void DijkstraPrint(int start, int end ,AdjMatrix G,int path[][MAXVEX]){
	int i = 2;
	int length = 0;
	printf( "\n\t��%s��%s�����·����:", G.vex[start].name, G.vex[end].name );
	printf( "  %s", G.vex[start].name );
	
	while(path[end][i]){   //��¼��·�� 
		printf("-->%s ",G.vex[path[end][i]].name);
		length += G.arcs[path[end][i-1]][path[end][i]];	
		i++;
	}
	printf( "-->%s", G.vex[end].name );
	length += G.arcs[path[end][i-1]][end];	
	printf( "������Ϊ%dM", length);
	printf( "\n");
 } 

//�ֲ˵� ���·�� 
void ShortPath(AdjMatrix G,int dist[],int path[][MAXVEX]){ 
	int i,j,s,e;
	int flag = 1;
	while (flag == 1){
		system("cls");
		printf("\t\t\t\t\t\t���������������·����ѯ������������\n");
		PrintPlace(&G);
		printf("\n\t\t\t\t\t���������:");
		scanf("%d",&s);
		printf("\t\t\t\t\t�����յ���:");
		scanf("%d",&e);
		if (s > G.vexnum || s <= 0 || e > G.vexnum || e < 0 || s == e){
			printf("\t\t\t\t\t\t�������!\n\n");
	    }
		else{
			ClearVisited(&G);   //�˵� 
			
			Dijkstra(&G,s,e,dist,path); //�㷨 
			DijkstraPrint(s,e,G,path);//��ӡ 
	
		}
		printf("\n\t\t\t\t\t\t�Ƿ������ѯ���·��?\n");
		printf("\t\t\t\t\t\t1:��\n");
		printf("\t\t\t\t\t\t0:�����ϼ��˵�\n");
		scanf("%d",&flag);
	}
	system("cls");
}

//·���������˵� 
void SearchPath(AdjMatrix G,int dist[],int path[][MAXVEX]){ 
	int x,flag = 1;
	while(flag == 1){  //�����˵� 
		printf("\t\t\t1. ���м�·��\n");  //����������ظ� 
		printf("\t\t\t2. ��̵ļ�·��(��ת����)\n");
		printf("\t\t\t3. ��ѷ���·��(���·������)\n");
		printf("\t\t\t0. �������˵�\n");
		printf("\t\t\t��ѡ������Ҫ�Ĳ���:");
		scanf("%d",&x);

		switch(x){
			case 1: system("cls");AllPath(G,dist,path);break;
			case 2: system("cls");LitterPath(G);break;
			case 3: system("cls");ShortPath(G,dist,path);break;
			case 0: flag = 0; break;
			default:printf( "\t\t\t\t\t\t\t������Ϣ����,����������!\n" ); break;
		}
	system("cls");
   }
}

//ע����Ϣ
void enroll(){
	char a[100];                   //ע���û���
	char b[100];                   //ע������
	char s[100];                   //�ٴ�ȷ������
	int  len;
	
	
   	printf("�����������û�����");
	scanf("%s",a);
	
	printf("�������������룺");
			
	reset: scanf("%s",b);     //�õ���if goto��� 

	    len = strlen(b);    //��ȡ���볤�� 
	   
	    if(len > 9){
		  printf("���볤�ȹ��������������ã�");
	      goto reset;    //if goto ���  
	    }
   	    printf("���ٴ����������õ����룺");
     	scanf("%s",s);
	
	    if(strcmp(b,s) == 0){       //�ַ����ȽϺ��� 
		    FILE *fp;
		
			fp=fopen("register.txt","at");     //ѡ��׷�ӷ�ʽ�����Դ�����Ϣ
		
			if(fp == NULL){
				printf("�ļ������ڻ�������ע��!");
				exit(1);                           
	     	}
		
			fprintf(fp,"%s %s\n",a,b);                    //�ַ���д�뺯������д�����
        	system("cls");
	    	printf("\n\t------ע��ɹ�------\n");
			fclose(fp);
		}
		else if(strcmp(b,s) != 0){
			printf("��������������벻һ�£��������������룡\n");
			goto reset;          //if goto ��� 
		}
}

//��½ҳ��
int land(){
	int  i = 0;      //i��Ϊ���ж����볤�� ������ 
	char a[10];                 
	char b[10];                   

	char user_name[10];           
	char user_passwords[10];      

	printf("�����������û�����");
	scanf("%s",user_name);

    printf("�������������룺");

	while(i < 9 && (user_passwords[i] = getch()) && user_passwords[i] != '\r'){   //������볬�� ���� �������з�������ѭ��
		printf("*");   //�������� 
		i++;
	}
	
	user_passwords[i] = 0;   //�ַ���������־ '/0' 
	
	FILE *fp;
	fp=fopen("register.txt","rt");       //�ִ��ļ� 
	
	if(fp == NULL){
		printf("�ļ�������!");
		exit(1);
	}
	
	while(fscanf(fp,"%s %s",a,b) != EOF){    //���ļ��ж��˺������Ƿ���ȷ     
		if(strcmp(a,user_name) == 0  &&  strcmp(b,user_passwords) == 0){   //�ַ����ȽϺ��������Ƿ���ȷ 
		 	system("cls");
			printf("\n\t\t\t--------��½�ɹ�--------\n");
			return 0;
		 } 
	}
	if(1){
		system("cls");
		printf("\n��Ϣ�������(����ע���ļ���Ϣ)\n");
	    land();
	}
	fclose(fp);
}

//�����µص����Ϣ 
void AddPlace(AdjMatrix *G){
	int s,e;
	char filename[30] = "introduce.txt";
	char filename1[30] = "flag.txt";
	
	
	int flag = 1;
	char p[20];
	char i[66];
	
	while (flag == 1){
		//���ӵص�ĵ���
		//���ӵص�Ľ��� 	
		
		printf("�������µص�ĵ�����");
		scanf("%s",p);	
		printf("�������µص�ļ�飺");
		scanf("%s",i);	
	
		G->vexnum += 1;  //��������1 
	 
		strcpy(G->vex[G->vexnum].name,p); 
		strcpy(G->vex[G->vexnum].info,i); 	
	
		FILE *fp;
		fp = fopen(filename,"at");
		if(fp == NULL){
			printf("\n���ܴ�!");
			exit(1);
	}
	
	fprintf(fp,"%s\n%s\n",G->vex[G->vexnum].name,G->vex[G->vexnum].info); 
	fclose(fp);

	FILE *fp1;
	fp1 = fopen(filename1,"wt");
	if(fp1 == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
	
	fprintf(fp1,"%d %d\n",G->vexnum,G->arcnum); 
	fclose(fp1);

	printf("\t\t��ӵص�ɹ����ɴ�\"introduce�ļ�\"�鿴��");  //ת���ַ� 
	printf( "\n\t\t\t\t\t\t�Ƿ������ӵص㣿\n" );
	printf( "\t\t\t\t\t\t1:��\n" );
	printf( "\t\t\t\t\t\t0:�����ϼ��˵�\n" );
	scanf( "%d", &flag );
	
	}
	system("cls"); 
}

//������·��	
void AddRoad(AdjMatrix *G){
	int s,e,weight;
	char filename[30] = "adj.txt";
	char filename1[30] = "flag.txt";
	int flag = 1;
	
	while(flag == 1){
		PrintPlace(G);  //��ӡ�ص����� 
	
   	    printf("����������·�ߵ������ţ�");
		scanf("%d",&s);
		printf("����������·�ߵ��յ���ţ�");
		scanf("%d",&e);
	
		printf("����������·��֮��ľ��룺");
		scanf("%d",&weight);		
		G->arcs[s][e] = G->arcs[e][s] = weight;
		
		FILE *fp;
		fp = fopen(filename,"at");
		if(fp == NULL){
			printf("\n���ܴ�!");
			exit(1);
		}
		fprintf(fp,"%10d %10d %10d\n",s,e,G->arcs[s][e]);
		fclose(fp);
		
		FILE *fp1;
		fp1 = fopen(filename1,"at");
		if(fp1 == NULL){
			printf("\n���ܴ�!");
			exit(1);
		}
		
		G->arcnum += 1; //����+1
		fprintf(fp1,"%d %d\n",G->vexnum,G->arcnum); 
		fclose(fp1); 

		system("cls");
		printf("\t\t���·�߳ɹ����ɴ�\"adj�ļ�\"�鿴��");  //ת���ַ� 
		printf( "\n\t\t\t\t\t\t�Ƿ�������·�ߣ�\n" );
		printf( "\t\t\t\t\t\t1:��\n" );
		printf( "\t\t\t\t\t\t0:�����ϼ��˵�\n" );
		scanf( "%d", &flag );
	}
	system("cls"); 
}
	
//ɾ��·�� 
void DelRoad(AdjMatrix *G){
	int s,e,weight,i,j;
	char filename[30] = "adj.txt";
	char filename1[30] = "flag.txt";
	int flag = 1;
	
	FILE *fp;
	fp = fopen(filename,"at");
	if(fp == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
	
	FILE *fp1;
	fp1 = fopen(filename1,"wt");
	if(fp == NULL){
		printf("\n���ܴ�!");
		exit(1);
	}
	
	while(flag == 1){
	
		PrintPlace(G);
	
		printf("�����볷��·�ߵ������ţ�");
		scanf("%d",&s);
		printf("�����볷��·�ߵ��յ���ţ�");
		scanf("%d",&e);
	
		//����adj�ļ������������s��e����ô������ֵ���������		
   		G->arcs[s][e] = G->arcs[e][s] = INFINITY;
  		fprintf(fp,"%10d %10d %10d\n",s,e,G->arcs[s][e]);
  	
	  	G->arcnum -= 1; //����-1
		fprintf(fp1,"%d %d\n",G->vexnum,G->arcnum); 
  		fclose(fp); 
   		fclose(fp1);
		system("cls");
		printf("\t\t����·�߳ɹ����ɴ�\"adj�ļ�\"�鿴��");  //ת���ַ� 
		printf( "\n\t\t\t\t\t\t�Ƿ��������·�ߣ�\n" );
		printf( "\t\t\t\t\t\t1:��\n" );
		printf( "\t\t\t\t\t\t0:�����ϼ��˵�\n" );
		scanf( "%d", &flag );   		    
   } 
	system("cls"); 	
} 

//�ο�
void User(){
	int x;
	int dist[MAXVEX];// ��¼�������·������ 
	int	path[MAXVEX][MAXVEX] = {0};//��¼��Ӧ·���ϵĸ�����
	AdjMatrix G;   //�ڽӾ���   
	Create(&G); 
    while(1){
		printf("\t\t\t1. У԰ƽ��ͼ\n");
		printf("\t\t\t2. �ص���Ϣ��ѯ\n");
		printf("\t\t\t3. ��·��ѯ\n");
		printf("\t\t\t0. �˳�\n"); 
		printf("\t\t\t��ѡ������Ҫ�Ĳ���:");
		scanf("%d",&x);
	
		switch(x){
		case 1: system("cls"); MapOutput(); break;
		case 2: system("cls"); IntroducePlace(G); break;
		case 3: system("cls"); SearchPath(G,dist,path); break;
		case 0: printf("\n\t\t\t\t\t\t\t"); exit(0); break;
		default: printf("\n������������������������������������Ϣ����,����������!!!����������������������������������������\n"); break;
		}
	} 
}

//����Ա�˵� 
void OwnerMeau(AdjMatrix G){
	int c;
	int x;
	int dist[MAXVEX];// ��¼�������·������ 
	int	path[MAXVEX][MAXVEX] = {0};//��¼��Ӧ·���ϵĸ�����
    while(1){
		printf("\t\t\t1. ����µص�\n");
		printf("\t\t\t2. �����·��\n");
		printf("\t\t\t3. ������·��\n");
		printf("\t\t\t4. У԰ƽ��ͼ\n");
		printf("\t\t\t5. �ص���Ϣ��ѯ\n");
		printf("\t\t\t6. ��·��ѯ\n");
		printf("\t\t\t0. �˳�\n"); 
		printf("\t\t\t��ѡ������Ҫ�Ĳ���:");
		scanf("%d",&c);
		getchar();
	
		switch(c){
			case 1: system("cls"); AddPlace(&G); break;
			case 2: system("cls"); AddRoad(&G); break;
			case 3: system("cls"); DelRoad(&G); break;
			case 4: system("cls"); MapOutput(); break;
			case 5: system("cls"); IntroducePlace(G); break;
			case 6: system("cls"); SearchPath(G,dist,path); break;
			case 0: printf("\n\t\t\t\t\t\t\t"); exit(0);
			default: printf("\n������������������������������������Ϣ����,����������!!!����������������������������������������\n"); break;	
    	}
	}
}

//����Ա��¼ 
void Owner(){
	int x;
	int dist[MAXVEX];// ��¼�������·������ 
	int	path[MAXVEX][MAXVEX] = {0};//��¼��Ӧ·���ϵĸ�����
	AdjMatrix G;   //��Ӿ��� 
	MapFile(G); 
	IntroduceFile(G);  //���ļ��д��������Ϣ 
	AdjFile(G);    //���ļ��д����ڽӾ�����Ϣ 
	Create(&G);
	
	system("cls");
	printf("\t\t1.��½\t\t\t2.ע�Ტ��¼\n");
    printf("��ѡ����ţ�");
    
    while(1){
		scanf("%d",&x);
		switch(x){
		 	case 1:  land(); OwnerMeau(G); break;
			case 2:  enroll(); land(); OwnerMeau(G); break;
			default: printf( "\n������������������������������������Ч,��������ȷ����!!!����������������������������������������\n"); break;
		}		
	} 
}

//������ 
int main(){
 	int flag;
	
    printf("��������������������������������������������������������������������������������������������\n"); 
    printf("\n\t\t\t��ӭʹ�������ʵ��ѧ����У������ϵͳ !\n\n");   
    printf("��������������������������������������������������������������������������������������������\n");
	printf("\n\n\n"); 
	
	//�ο�or����Ա 
	printf("\t\t1.�����ο�\t\t\t2.���ǹ���Ա\n");
	printf("��ѡ����ţ�");
	
	while(1){
		scanf("%d",&flag);
		switch(flag){
		 	case 1: system("cls"); User(); break;
			case 2: system("cls"); Owner(); break;
			default: printf("\n������������������������������������Ч,��������ȷ����!!!����������������������������������������\n"); break;
		}
	} 
}
