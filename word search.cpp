#include <bits/stdc++.h>

using namespace std;

const int N=102;
int n,m,q;
pair<int,int> ans;
char tab[N][N];
string s;

bool safe(int i,int j)
{
    return i>-1 && i<n && j>-1 && j<m;
}

int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={-1,0,1,-1,0,1,-1,1};

pair<int,int> exist(int i, int j, int id, string s, int direction,int sz)
{
    if (id > sz-1)
        return {i,j};

    int di = i + dx[direction];
    int dj = j + dy[direction];

    if (!safe(di,dj))
        return {-1,-1};

    if (tab[di][dj] != s[id])
        return {-1,-1};

    return exist(di,dj,id+1,s,direction,sz);
}

int main()
{
    //freopen("a.txt","r",stdin);
    cin>>n>>m>>q;

    for (int i=0 ; i<n ; i++)
    {
        cin>>s;
        for (int j=0 ; j<m ; j++)
        {
            tab[i][j]=s[j];
        }
    }

    while(q--)
    {
        cin>>s;

        bool bo = false;
        for (int i=0 ; i<n ; i++)
        {
            if (bo)
                break;

            for (int j=0 ; j<m ; j++)
            {
                if (bo)
                    break;

                if (tab[i][j]==s[0])
                {
                    ans = {-1,-1};
                    for (int c=0 ; c<8 ; c++)
                    {
                        int di = i + dx[c];
                        int dj = j + dy[c];
                        if (!safe(di,dj))
                            continue;

                        if (tab[di][dj] != s[1])
                            continue;

                        pair<int,int> r = exist(di,dj,2,s,c,s.size());

                        if (r.first != -1)
                        {
                            bo = true;
                            if (ans.first == -1)
                                ans = {r.first, r.second};
                            else
                            {
                                if (r.first<ans.first)
                                    ans = {r.first, r.second};
                                else if (r.second < ans.second)
                                    ans = {r.first, r.second};
                            }
                        }
                    }

                    if (bo)
                    {
                        cout<<i<<" "<<j<<" "<<ans.first<<" "<<ans.second<<'\n';
                        break;
                    }
                }
            }
        }

        if (!bo)
        {
            cout<<"-1\n";
        }
    }

    return 0;
}
