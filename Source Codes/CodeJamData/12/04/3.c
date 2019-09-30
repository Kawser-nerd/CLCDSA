#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pgcd(int a, int b)
{
	int c;
	if(b > a)
	{
		c = a;
		a = b;
		b = c;
	}
	while(b > 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}


int main()
{
	int T, H, W, D, i, j, k, x1, x2, d1, d2, y1, y2, a1, a2, avancee, z1, z2, v1, v2;
	int abs[6000], ord[6000], nb, p, q, P, Q, horizontal, vertical, enquestion, fois, destroyed, m1, m2, racine, total;
	char **tableau;
	scanf("%d", &T);
	for(i = 0; i < T; i++)
	{
		printf("Case #%d: ", i+1);
		scanf("%d %d %d\n", &H, &W, &D);
		tableau = malloc(H*sizeof(char*));
		for(j = 0; j < H; j++)
		{
			tableau[j] = malloc(W*sizeof(char));
			for(k = 0; k < W; k++)
			{
				scanf("%c", &tableau[j][k]);
				if(tableau[j][k] == 'X')
				{
					x1 = j;
					x2 = k;
				}
			}
			scanf("\n");
		}
		
		// On recherche une direction susceptible d'être bonne
		// A savoir des nombres p et q dont le pgcd est 1, tels que
		// p²+q² <= D² (p et q peuvent être négatifs)
		nb = 0;

		for(p = 1; p < D; p++)
		{
			for(q = 1; p*p + q*q <= D*D; q++)
			{
				if(pgcd(p, q) == 1)
				{
					abs[nb] = p;
					ord[nb] = q;
					nb++;
					abs[nb] = -p;
					ord[nb] = q;
					nb++;
					abs[nb] = p;
					ord[nb] = -q;
					nb++;
					abs[nb] = -p;
					ord[nb] = -q;
					nb++;
				}
			}
		}
		abs[nb] = 0;
		ord[nb] = 1;
		nb++;
		abs[nb] = 0;
		ord[nb] = -1;
		nb++;
		abs[nb] = 1;
		ord[nb] = 0;
		nb++;
		abs[nb] = -1;
		ord[nb] = 0;
		nb++;



		// Maintenant on doit tester les nb cas.
		total = 0;
		for(j = 0; j < nb; j++)
		{
			avancee = 0;
			destroyed = 0;
			// On teste le cas j
			// On va compter en (2*p*q)-emes.
			// Initialement, on se trouve à la position
			p = abs[j];
			q = ord[j];
			P = fabs((double)p);
			Q = fabs((double)q);
			if(p != 0 && q != 0)
			{
			y1 = P*Q*(2*x1+1);
			y2 = P*Q*(2*x2+1);
			z1 = y1;
			z2 = y2;
			d1 = p/P;
			d2 = q/Q;
			// On va rajouter alpha*(p,q)/2pq
			// On est à 2pq - y1%(2pq) du suivant vers la droite
			// Ce qui correspond à un alpha de 
			a1 = 2*Q-(y1%(2*P*Q))/P;
			a2 = 2*P-(y2%(2*P*Q))/Q;
			k = 0;
			fois = D/sqrt((double)(P*P+Q*Q));
			while(destroyed == 0 && avancee < 2*P*Q*fois)
			{
				k++;
				if(a1 < a2)
				{
					// On s'occupe du a1
					y1 += a1*P;
					y2 += a1*Q;
					z1 += a1*d1*P;
					z2 += a1*d2*Q;
					m1 = z1-a1*d1*P/2;
					m2 = z2-a1*d2*Q/2;
					avancee += a1;
					// ligne verticale
					if(d1 == 1 && tableau[z1/(2*P*Q)][z2/(2*P*Q)] == '#')
					{
						d1 = -1;
					}
					else if(d1 == -1 && tableau[z1/(2*P*Q)-1][z2/(2*P*Q)] == '#')
					{
						d1 = 1;
					}
				}
				else if(a2 < a1)
				{
					// On s'occupe du a2
					y1 += a2*P;
					y2 += a2*Q;
					z1 += a2*d1*P;
					z2 += a2*d2*Q;
					m1 = z1-a2*d1*P/2;
					m2 = z2-a2*d2*Q/2;
					avancee += a2;
					// ligne horizontale
					if(d2 == 1 && tableau[z1/(2*P*Q)][z2/(2*P*Q)] == '#')
					{
						d2 = -1;
					}
					else if(d2 == -1 && tableau[z1/(2*P*Q)][z2/(2*P*Q)-1] == '#')
					{
						d2 = 1;
					}
				}
				else // égalité, on est dans un coin
				{
					y1 += a1*P;
					y2 += a1*Q;
					z1 += a1*d1*P;
					z2 += a1*d2*Q;
					m1 = z1-a1*d1*P/2;
					m2 = z2-a1*d2*Q/2;
					avancee += a1;
					// coin
					v1 = z1/(2*P*Q);
					v2 = z2/(2*P*Q);
					if(d1 == -1 && d2 == -1)
					{
						v1--;
						v2--;
					}
					else if(d1 == -1 && d2 == 1)
					{
						v1--;
					}
					else if(d1 == 1 && d2 == -1)
					{
						v2--;
					}
					if(tableau[v1][v2] == '#') enquestion = 1;
					else enquestion = 0;
					if(tableau[v1-d1][v2] == '#') horizontal = 1;
					else horizontal = 0;
					if(tableau[v1][v2-d2] == '#') vertical = 1;
					else vertical = 0;
					
					if(enquestion == 1 && horizontal == 1 && vertical == 1)
					{
						d1 = -d1;
						d2 = -d2;
					}
					else if(enquestion == 1 && horizontal == 0 && vertical == 0)
					{
						destroyed = 1;
					}
					else if(enquestion == 1 && horizontal == 1 && vertical == 0)
					{
						d2 = -d2;
					}
					else if(enquestion == 1 && horizontal == 0 && vertical == 1)
					{
						d1 = -d1;
					}
				}
				if(k > 1 && m1 % (2*P*Q) == P*Q && m2 % (2*P*Q) == P*Q && m1/(2*P*Q) == x1 && m2/(2*P*Q) == x2) destroyed = 2;

				a1 = 2*Q-(y1%(2*P*Q))/P;
				a2 = 2*P-(y2%(2*P*Q))/Q;
			}
			if(destroyed == 2)
			{
				total++;
			}
			}

			else if(p == 0)
			{

			y1 = (2*x1+1);
			y2 = (2*x2+1);
			z1 = y1;
			z2 = y2;
			d2 = q/Q;
			// On va rajouter alpha*(p,q)/2pq
			// On est à 2pq - y1%(2pq) du suivant vers la droite
			// Ce qui correspond à un alpha de 
			a2 = 2-(y2%(2))/Q;
			k = 0;
			fois = D;
			while(destroyed == 0 && avancee < 2*fois)
			{
				k++;
					// On s'occupe du a2
					y2 += a2*Q;
					z2 += a2*d2*Q;
					m2 = z2-a2*d2*Q/2;
					avancee += a2;
					// ligne horizontale
					if(d2 == 1 && tableau[x1][z2/(2)] == '#')
					{
						d2 = -1;
					}
					else if(d2 == -1 && tableau[x1][z2/(2)-1] == '#')
					{
						d2 = 1;
					}
				
			
				if(k > 1 && m2/2 == x2) destroyed = 2;
				a2 = 2-(y2%(2))/Q;
			}
			if(destroyed == 2)
			{
				total++;
			}





			}

			else if(q == 0)
			{

			y1 = (2*x1+1);
			y2 = (2*x2+1);
			z1 = y1;
			z2 = y2;
			d1 = p/P;
			// On va rajouter alpha*(p,q)/2pq
			// On est à 2pq - y1%(2pq) du suivant vers la droite
			// Ce qui correspond à un alpha de 
			a1 = 2-(y1%(2))/P;
			k = 0;
			fois = D;
			while(destroyed == 0 && avancee < 2*fois)
			{
				k++;
					// On s'occupe du a2
					y1 += a1;
					z1 += a1*d1;
					m1 = z1-a1*d1/2;
					avancee += a1;
					// ligne horizontale
					if(d1 == 1 && tableau[z1/2][x2] == '#')
					{
						d1 = -1;
					}
					else if(d1 == -1 && tableau[(z1/2)-1][x2] == '#')
					{
						d1 = 1;
					}
				
			
				if(k > 1 && m1/2 == x1) destroyed = 2;
				a1 = 2-(y1%(2))/P;
			}
			if(destroyed == 2)
			{
				total++;
			}



			}



		}
		printf("%d\n", total);

		for(j = 0; j < H; j++) free(tableau[j]);
		free(tableau);
	}
	return 0;
}
