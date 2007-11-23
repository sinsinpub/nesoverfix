#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include <windows.h>

#define MAXROM 2048

void appendsep(char *p)
{
	char *pp;
	pp=strchr(p,0);
	if(*(--pp)!='\\')
		*(++pp)='\\',*(++pp)='\0';
}

unsigned searchrom(char *path,char (*name)[260],unsigned long *size)
{
	BOOL done;
	HANDLE hFind;
	WIN32_FIND_DATA ffblk;
	unsigned cnt=0;
	cout<<"Searching roms at "<<path<<"......"<<endl;
	done=TRUE;
	hFind=FindFirstFile(path,&ffblk);
	if(hFind==INVALID_HANDLE_VALUE) done=FALSE;
	while(done)
	{
		strcpy((char *)(name+cnt),ffblk.cFileName);
		*(size+cnt)=ffblk.nFileSizeLow;
		done=FindNextFile(hFind,&ffblk);
		cnt++;
		if(cnt>=MAXROM)
		{
			cout<<"Too many roms in this folder!"<<endl;
			break;
		}
	}
	return cnt;
}

int askforfix(void)
{
	char ch;
	printf("Fix it with correct size?(Yes,No,All,Cancel) ");
	while(1)
	{
		ch=toupper(getche());
		printf("\n");
		if(ch=='A') return -1;
		if(ch=='C') return 0;
		if(ch=='Y') return 1;
		if(ch=='N') return 2;
	}
}

int isneedfix(char *filename,unsigned long *realsize)
{
	int ret=0,cc=0;
	char ch;
	FILE *fp;
	if((fp=fopen(filename,"rb"))==NULL)
	{
		cout<<"Access error - "<<filename<<endl;
		exit(1);
	}
	while(!feof(fp))
	{
		ch=fgetc(fp);
		if(ch=='\x20')
		{
			cc++;
			continue;
		}
		if(ch=='\x0d'&&cc>0)
		{
			cc++;
			continue;
		}
		if(ch=='\x0a'&&cc==81)
		{
			ret=1;
			*realsize=ftell(fp)-82;
			break;
		}
		cc=0;
	}
	fclose(fp);
	return ret;
}

void fixit(char *filename,unsigned long realsize,bool overwrite)
{
	unsigned long curp;
	char *nn,*p;
	FILE *fp1,*fp2;
	nn=(char *)malloc(260);
	strcpy(nn,filename);
	p=strchr(nn,0);
	*(--p)='X';
	*(--p)='I';
	*(--p)='F';
	cout<<"Fixing "<<filename<<"......";
	if((fp1=fopen(filename,"rb"))==NULL)
	{
		cout<<endl<<"Access error - "<<filename<<endl;
		exit(1);
	}
	if((fp2=fopen(nn,"wb"))==NULL)
	{
		cout<<endl<<"Access error - "<<nn<<endl;
		exit(1);
	}
	for(curp=0;curp<realsize;curp++)
		fputc(fgetc(fp1),fp2);
	fclose(fp1);
	fclose(fp2);
	if(overwrite)
	{
		DeleteFile(filename);
		MoveFile(nn,filename);
	}
	cout<<"OK"<<endl;
	free(nn);
}

void fixrom(char *path,char (*name)[260],unsigned long *size,unsigned cnt,bool overwrite)
{
	int ans=0;
	unsigned i,fx=0;
	unsigned long rs;
	char *sah;
	sah=(char *)malloc(260);
	cout<<"Examining roms if need fixing......."<<endl;
	for(i=0;i<cnt;i++)
	{
		strcpy(sah,path);
		strcat(sah,(char *)(name+i));
		#ifdef DEBUG
		gi=i;
		strcpy(fn1,sah);
		#endif
		if(isneedfix(sah,&rs))
		{
			#ifdef DEBUG
			strcpy(fn2,sah);
			#endif
			cout<<sah<<" needs to be fixed"<<endl;
			cout<<"Its size now is "<<*(size+i)<<", but it should be "<<rs<<endl;
			if(ans>=0) ans=askforfix();
			if(ans==0) break;
			if(ans==1||ans==-1)
			{
				fixit(sah,rs,overwrite);
				fx++;
			}
		}
	}
	if(fx==0)
		cout<<"No rom needs to be fixed"<<endl;
	else
		cout<<fx<<" rom(s) have been fixed successfully"<<endl;
	free(sah);
}

int main(int argc,char *argv[])
{
	char *path,*sah;
	char name[MAXROM][260];
	int i;
	unsigned cnt;
	unsigned long size[MAXROM];
	bool overwrite=FALSE;
	path=(char *)malloc(260);
	sah=(char *)malloc(260);
	if(argc>1)
	{
		for(i=1;i<argc;i++)
		{
			if(strcmp(argv[i],"/?")==0)
			{
				cout<<"NES Over-dumped Rom Fixer Version 0.92 for Win32 "<<endl<<endl;
				cout<<"    NESFIX [[drive:]path] [/option] "<<endl<<endl;
				cout<<"    [[drive:]path] "<<endl;
				cout<<"            Sepcifies the path space at where the roms are. "<<endl;
				cout<<"    /Y      Specifies if replace over-dumped ROM with fixed one. "<<endl;
				cout<<"    /?      Displays this help screen. "<<endl<<endl;
				cout<<"Copyright (c) sin_sin, 2002, 2004. All Rights Reserved. "<<endl;
				exit(0);
			}
			if(strcmp(argv[i],"/Y")==0||strcmp(argv[i],"/y")==0)
			{
				overwrite=TRUE;
			}
			else
			{
				strcpy(path,argv[i]);
				appendsep(path);
			}
		}
	}
	else
		strcpy(path,".\\");
	strcpy(sah,path);
	strcat(sah,"*.NES");
	cout<<"NES Rom Fixer Version 0.92 for Win32 "<<endl;
	cout<<"Copyright (c) sin_sin, 2002, 2004. All Rights Reserved. "<<endl<<endl;
	cnt=searchrom(sah,name,size);
	if(cnt==0)
	{
		cout<<"No rom found - "<<path<<endl;
		return 1;
	}
	cout<<cnt<<" rom(s) found"<<endl;
	fixrom(path,name,size,cnt,overwrite);
	return 0;
}
