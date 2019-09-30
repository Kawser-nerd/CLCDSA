#include "stdio.h"
#include "stdlib.h"

typedef enum {NONE=-1, UNMALTED=0, MALTED=1, ALL=2} Pref;
typedef enum {FALSE,TRUE} Bool;

int main() {
	unsigned cases = 0;
	unsigned cas = 0;

	scanf("%u", &cases);

	for(cas = 1; cas <= cases; cas++) {
		unsigned flavours = 0;
		unsigned flavour = 0;

		unsigned customers = 0;
		unsigned customer = 0;

		Pref *prefs = NULL;

		int *malts = NULL;

		scanf("%u", &flavours);
		scanf("%u", &customers);
		
		prefs = (Pref *)malloc(sizeof(Pref)*flavours*customers);

		for(customer = 0; customer < customers; customer++) {
			for(flavour = 0; flavour < flavours; flavour++)
				prefs[customer*flavours+flavour] = NONE;
		}

		malts = (int *)malloc(sizeof(unsigned)*customers);
		for(customer = 0; customer < customers; customer++) {
			malts[customer] = -1;
		}

		for(customer = 0; customer < customers; customer++) {
			unsigned p = 0;

			scanf("%u", &p);
			
			for(; p > 0; p--) {
				unsigned f = 0;
				unsigned m = 0;

				unsigned i = 0;

				scanf("%u", &f);
				scanf("%u", &m);

				--f; /* flavours are indexed from 1 in the problem spec, 0 in the program :( */
				if(m == 1)
					malts[customer] = f;

				i = customer*flavours+f;

				if(prefs[i] == NONE)
					prefs[i] = m;
				else {
					/* since no pair will occur twice in one customer, this customer will be pleased with anything */
					prefs[i] = ALL;
				}
			}
		}

		{
			Pref *prods = NULL;
			Bool unhappy = TRUE;
			Bool possible = TRUE;
			unsigned i = 0;

			prods = (Pref *)malloc(sizeof(Pref)*flavours);
			
			for(flavour = 0; flavour < flavours; flavour++) {
				prods[flavour] = UNMALTED;
			}

			while(unhappy && possible) {
				unhappy = FALSE;
				for(customer = 0; customer < customers; customer++) {
					Bool happy = FALSE;

					for(flavour = 0; flavour < flavours; flavour++) {
						i = customer*flavours+flavour;

						if(prefs[i] == ALL || prefs[i] == prods[flavour]) {
							happy = TRUE;
							break; /* customer is satisfied */
						}
					}

					if(!happy) {
						unhappy = TRUE;
						if(malts[customer] == -1) { /* then malting something won't make this customer happy :( */
							possible = FALSE;
							break;
						}
						prods[malts[customer]] = MALTED;
					}
				}
			}
			if(!possible)
				printf("Case #%u: IMPOSSIBLE\n", cas);
			else { /* must be happy */
				printf("Case #%u:", cas);
				for(flavour = 0; flavour < flavours; flavour++)
					printf(" %u", prods[flavour]);
				putchar('\n');
			}
		}
	}

	return 0;
}
