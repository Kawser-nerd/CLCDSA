#include <stdio.h>

char directions[4] = {'N', 'E', 'S', 'W'};
int class[24] = {
	0, 2, 3, 15, 16, 33, 34, 54, 55, 79,
	80, 107, 108, 138, 139, 171, 172, 207, 208, 244,
	245, 284, 285, 326
};


int main(void){
	int deg, dis, diff = 2250;
	char *dir;
	int c = 12;
	scanf("%d %d", &deg, &dis);
	deg *= 10;
	if(1125 + diff * 0 <= deg && deg < 1125 + diff * 1)dir = "NNE";
	else if(1125 + diff * 1 <= deg && deg < 1125 + diff * 2)dir = "NE";
	else if(1125 + diff * 2 <= deg && deg < 1125 + diff * 3)dir = "ENE";
	else if(1125 + diff * 3 <= deg && deg < 1125 + diff * 4)dir = "E";
	else if(1125 + diff * 4 <= deg && deg < 1125 + diff * 5)dir = "ESE";
	else if(1125 + diff * 5 <= deg && deg < 1125 + diff * 6)dir = "SE";
	else if(1125 + diff * 6 <= deg && deg < 1125 + diff * 7)dir = "SSE";
	else if(1125 + diff * 7 <= deg && deg < 1125 + diff * 8)dir = "S";
	else if(1125 + diff * 8 <= deg && deg < 1125 + diff * 9)dir = "SSW";
	else if(1125 + diff * 9 <= deg && deg < 1125 + diff * 10)dir = "SW";
	else if(1125 + diff * 10 <= deg && deg < 1125 + diff * 11)dir = "WSW";
	else if(1125 + diff * 11 <= deg && deg < 1125 + diff * 12)dir = "W";
	else if(1125 + diff * 12 <= deg && deg < 1125 + diff * 13)dir = "WNW";
	else if(1125 + diff * 13 <= deg && deg < 1125 + diff * 14)dir = "NW";
	else if(1125 + diff * 14 <= deg && deg < 1125 + diff * 15)dir = "NNW";
	else dir = "N";
	dis = (dis * 100 / 60 + 5) / 10;
	for(int i = 0; i < 12; i++)
		if(class[i * 2] <= dis && dis <= class[i * 2 + 1]){
			c = i;
			break;
		}
	if(c == 0)dir = "C";
	printf("%s %d\n", dir, c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &deg, &dis);
  ^