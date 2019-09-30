#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct vlong
{
	int len;
	char pos[60];
	
	void set_len()
	{
		len = strlen(pos);
		return;
	}
	
	void normalize()
	{
		int z_len;
		int k;
		
		z_len = 0;
		while ( (pos[z_len] == '0') && (z_len < len) )
		{
			z_len++;
		}
		
		if ( len == z_len ) z_len = len - 1;
		len = len - z_len;
		for ( k = 0; k < len; k++ )
		{
			pos[k] = pos[k+z_len];
		}
		pos[len] = '\0';
		
		return;
	}
	
	vlong operator - (vlong param);
	vlong operator % (vlong param);
	
} t[1000];

int vl_cmp(vlong vl1,vlong vl2)
{
	if ( vl1.len > vl2.len )
	{
		return 1;
	}
	else if ( vl1.len < vl2.len )
	{
		return -1;
	}
	else
	{
		return ( strcmp(vl1.pos,vl2.pos) );
	}
}

vlong shl(vlong vl, int num_pos)
{
	int k;
	vlong ans;
	
	ans.len = vl.len + num_pos;
	for ( k = 0; k < vl.len; k++ )
	{
		ans.pos[k] = vl.pos[k];
	}
	for ( k = vl.len; k < ans.len; k++ )
	{
		ans.pos[k] = '0';
	}
	ans.pos[ans.len] = '\0';
	
	ans.normalize();
	return ans;
}

vlong vlong::operator - (const vlong param)
{
	vlong ans;
	int k,cur_dig;
	bool carry;
	
	ans.len = len;
	ans.pos[len] = '\0';
	
	carry = false;
	for ( k = 0; k < len; k++ )
	{
		cur_dig = 10 + pos[len-1-k] - (carry?1:0) - ((k<param.len)?param.pos[param.len-1-k]:'0');
		ans.pos[len-1-k] = '0' + (cur_dig % 10);
		if ( cur_dig < 10 )
		{
			carry = true;
		}
		else
		{
			carry = false;
		}
	}
	
	ans.normalize();
	return ans;
}

vlong vlong::operator % (vlong param)
{
	vlong ans;
	vlong sh_d;
	int k;
	
	ans.len = len;
	for ( k = 0; k < len; k++ )
	{
		ans.pos[k] = pos[k];
	}
	ans.pos[len] = '\0';
	
	if ( !( (param.len == 1) && (param.pos[0] == '0') ) )
	{
		k = 0;
		while ( vl_cmp(ans,shl(param,k)) >= 0 )
		{
			k++;
		}
		k--;
		
		while ( k >= 0 )
		{
			if ( vl_cmp(ans,shl(param,k)) >= 0 )
			{
				ans = ans - shl(param,k);
			}
			else
			{
				k--;
			}
		}
	}
	
	ans.normalize();
	return ans;
}

vlong gcd(vlong vl1, vlong vl2)
{
	vlong ans;
	
	if ( vl_cmp(vl1,vl2) < 0 )
	{
		ans = vl1;
		vl1 = vl2;
		vl2 = ans;
	}
	
	
	while ( !( (vl2.len == 1) && (vl2.pos[0] == '0') ) )
	{
		ans = vl1 % vl2;
		vl1 = vl2;
		vl2 = ans;
	}
	
	ans = vl1;
	return ans;
}

int main()
{
	int c,C;
	int n,N;
	int recent;
	
	vlong recent_val;
	vlong cur_gcd;
	
	cin >> C;
	
	for ( c = 0; c < C; c++ )
	{
		
		// get inputs and select the most recent one;
		cin >> N;
		recent = 0;
		for ( n = 0; n < N; n++ )
		{
			cin >> t[n].pos;
			t[n].set_len();
			t[n].normalize();
			
			if ( vl_cmp(t[recent],t[n]) > 0 ) recent = n;
		}
		
		// subtract min off others
		for ( n = 0; n < N; n++ )
		{
			if ( !(n == recent) )
			{
				t[n] = t[n] - t[recent];
			}
		}
		recent_val = t[recent];
		t[recent] = t[recent] - t[recent];
		
		// compute the gcd (adding t[n]s one by one)
		cur_gcd = t[0];
		for ( n = 1; n < N; n++ )
		{
			cur_gcd = gcd(cur_gcd,t[n]);
		}
		
		// compute apocalypsis time
		recent_val = recent_val % cur_gcd;
		if ( (recent_val.len == 1) && (recent_val.pos[0] == '0') )
		{
		}
		else
		{
			recent_val = cur_gcd - recent_val;
		}
		
		cout << "Case #" << c + 1 << ": " << recent_val.pos << "\n";
	}
	
	return 0;
}