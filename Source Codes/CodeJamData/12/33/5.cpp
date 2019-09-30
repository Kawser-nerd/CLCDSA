#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long LL;
typedef pair<LL,int>P;

P a[100],b[100];
int N,M;

LL memo[100][100];

LL F(int ai, int bi, LL aa, LL bb)
{
	if(ai>=N || bi>=M)
		return 0;

	if(!aa && !bb)
	{
		LL &res = memo[ai][bi];
		if(res>=0)
			return res;
		LL c;
		if(a[ai].second==b[bi].second && (c=min(a[ai].first,b[bi].first))>0 )
		{
			return res = c + F(ai,bi,c,c);
		}
		else
			return res = max( F(ai+1,bi,0,bb), F(ai,bi+1,aa,0) );
	}
	else
	{
		LL c;
		if(a[ai].second==b[bi].second && (c=min(a[ai].first-aa,b[bi].first-bb))>0 )
		{
			return c+F(ai,bi,aa+c,bb+c);
		}
		else
			return max( F(ai+1,bi,0,bb), F(ai,bi+1,aa,0) );
	}
}

int main()
{
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum = 1; caseNum <= T; ++caseNum)
	{
		memset(memo,-1,sizeof(memo));
		scanf("%d%d",&N,&M);
		int i;
		for(i=0; i<N; ++i)
			scanf("%lld%d",&a[i].first,&a[i].second);
		for(i=0; i<M; ++i)
			scanf("%lld%d",&b[i].first,&b[i].second);

		printf("Case #%d: %lld\n", caseNum,F(0,0,0,0));
	}
	return 0;
}
/*

箱とおもちゃ、2つのラインがある
箱とおもちゃは、それぞれTypeがある

あなたはまず、最初の箱と最初のおもちゃを手にする
あなたは以下の操作ができる
・あなたはいつでも、手の箱を捨てて次の箱を手に取れる
・あなたはいつでも、手のおもちゃを捨てて次のおもちゃを手に取れる
・もし箱とおもちゃが同じ型の場合、おもちゃを箱に入れて発送する
最大、何個発送できますか？


ラインで製造する個数は非常に多いが、それぞれのTypeが連続する個数は100個以下と少ない
A,B、それぞれのラインでTypeごとのDPに出来れば早いんだけど・・a,bの個数も管理しないといけない
・・・それともグラフの問題に落ちるの？

・・・少なくとも、いま手にしているTypeが同じなら、min(おもちゃ、箱)を一気に発送すればいい
違った場合、どちらかを変えればいい

・・・メモ化再帰で終わるか？

・・・オーダー分からないけど、とりあえずSmall回そう
Smallは1秒もかからなかった、さてLargeは？




*/
