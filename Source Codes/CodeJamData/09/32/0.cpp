#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

struct vv {
	double x, y, z;
};

int main() {
	int T; scanf("%d",&T);
	for (int test=1;test<=T;test++) {
		int NN; scanf("%d",&NN);
		double N = (double)NN;
		vv start, velocity;
		start.x=start.y=start.z=velocity.x=velocity.y=velocity.z=0;
		for (int i = 0; i < NN; i++) {
			vv tmp;
			int x,y,z;
			scanf("%lf%lf%lf",&tmp.x,&tmp.y,&tmp.z);
			start.x += tmp.x/N;
			start.y += tmp.y/N;
			start.z += tmp.z/N;
			scanf("%lf%lf%lf",&tmp.x,&tmp.y,&tmp.z);
			velocity.x += tmp.x/N;
			velocity.y += tmp.y/N;
			velocity.z += tmp.z/N;
		}
		int flag=0;
		if (velocity.x*velocity.x+velocity.y*velocity.y+velocity.z*velocity.z < .00000001) {
			flag=1;
		}
		double amt = start.x*velocity.x + start.y*velocity.y + start.z * velocity.z;
		amt /= -(velocity.x*velocity.x+velocity.y*velocity.y+velocity.z*velocity.z);
		printf("Case #%d: ",test);
		if (flag||amt < 0) {
			vv tmp;
			tmp.x = start.x;
			tmp.y = start.y;
			tmp.z = start.z;
			printf("%.8f %.8f\n",sqrt(tmp.x*tmp.x+tmp.y*tmp.y+tmp.z*tmp.z),0);
		} else {
			vv tmp;
			tmp.x = start.x + amt*velocity.x;
			tmp.y = start.y + amt*velocity.y;
			tmp.z = start.z + amt*velocity.z;
			printf("%.8f %.8f\n",sqrt(tmp.x*tmp.x+tmp.y*tmp.y+tmp.z*tmp.z),amt);
		}
	}
}