#include <stdio.h>
#include <string.h>
struct child_data{
    int p;char name[110];
};
struct node_data{
    int sc;struct child_data child[3000];
}node[5000];
int s;

int main(void)
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    int i,j,w,pre,k,res,t_case,t0,n,m,f;
    char path[110],dir[110];
    scanf("%d",&t_case);
    for (t0=1;t0<=t_case;++t0)
    {
        res=s=0;node[0].sc=0;
        scanf("%d%d ",&n,&m);
        for (i=0;i<n;++i)
        {
            gets(path);k=0;
            for (pre=1,j=1;path[j];++j)
            {
                if (path[j]=='/')
                {
                    strncpy(dir,path+pre,j-pre);dir[j-pre]='\0';
                    for (f=0,w=0;w<node[k].sc;++w)
                        if (strcmp(dir,node[k].child[w].name)==0)
                        {
                            f=1;k=node[k].child[w].p;break;
                        }
                    if (!f)
                    {
                        strcpy(node[k].child[node[k].sc].name,dir);
                        node[k].child[node[k].sc++].p=++s;
                        k=node[k].child[node[k].sc-1].p;node[k].sc=0;
                    }
                    pre=j+1;
                }
            }
            strncpy(dir,path+pre,j-pre);dir[j-pre]='\0';
            for (f=0,w=0;w<node[k].sc;++w)
                if (strcmp(dir,node[k].child[w].name)==0)
                {
                    f=1;k=node[k].child[w].p;break;
                }
            if (!f)
            {
                strcpy(node[k].child[node[k].sc].name,dir);
                node[k].child[node[k].sc++].p=++s;
                k=node[k].child[node[k].sc-1].p;node[k].sc=0;
            }
        }
        for (i=0;i<m;++i)
        {
            gets(path);k=0;
            for (pre=1,j=1;path[j];++j)
            {
                if (path[j]=='/')
                {
                    strncpy(dir,path+pre,j-pre);dir[j-pre]='\0';
                    for (f=0,w=0;w<node[k].sc;++w)
                        if (strcmp(dir,node[k].child[w].name)==0)
                        {
                            f=1;k=node[k].child[w].p;break;
                        }
                    if (!f)
                    {
                        strcpy(node[k].child[node[k].sc].name,dir);
                        node[k].child[node[k].sc++].p=++s;
                        k=node[k].child[node[k].sc-1].p;node[k].sc=0;
                        ++res;
                    }
                    pre=j+1;
                }
            }
            strncpy(dir,path+pre,j-pre);dir[j-pre]='\0';
            for (f=0,w=0;w<node[k].sc;++w)
                if (strcmp(dir,node[k].child[w].name)==0)
                {
                    f=1;k=node[k].child[w].p;break;
                }
            if (!f)
            {
                strcpy(node[k].child[node[k].sc].name,dir);
                node[k].child[node[k].sc++].p=++s;
                k=node[k].child[node[k].sc-1].p;node[k].sc=0;
                ++res;
            }
        }
        printf("Case #%d: %d\n",t0,res);
    }

    fclose(stdin);fclose(stdout);
    return 0;
}
