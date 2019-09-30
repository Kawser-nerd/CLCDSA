#include <stdio.h>
#include <stdint.h>

#define COMBINE(a, b) ((a) << 8 | (b))
#define TOP(x) ((x) >> 8)
#define BOTTOM(x) ((x) & 0xFF)
#define MARK(x, m) ((x) | (m) << 16)
#define UNMARK(x) (uint16_t)(x)
#define GETMARK(x) ((x) >> 16)
#define INDIAG(a, b) COMBINE((a) + (b) - 99 >> 1, (a) + 99 - (b) >> 1)
#ifdef TESTING
#define MIDIAG(a, b) (printf("D: %u %u\n", a, b), MARK(INDIAG(a, b), 5))
#else
#define MIDIAG(a, b) MARK(INDIAG(a, b), 5)
#endif

int main(int argc, char **argv)
{
	unsigned int no_cases, case_no;
	unsigned int size, no_left, a, b, t, p, i;
	uint32_t placement[324], *placement_end;
	scanf("%u", &no_cases);
	getchar();
	for (case_no = 0; case_no != no_cases; case_no++)
	{
		char row[101] = {}, column[101] = {},
		 sd[199] = {}, dd[199] = {};
		unsigned char freed[199],
		 *freed_end = freed, *freed_place = freed;
		placement_end = placement;
		scanf("%u%u", &size, &no_left);
		getchar();
		while (no_left--)
		{
			t = getchar();
			t = t == 'x' ? 1 : t == '+' ? 2 : 3;
			scanf("%u%u", &a, &b);
			getchar();
			p = COMBINE(--a, --b);
			*placement_end++ = MARK(p, t);
			if (t != 2)
			{
				row[a]++;
				column[b]++;
			}
			if (t != 1)
			{
				sd[a + b]++;
				dd[a + 99 - b]++;
			}
		}
		
		a = -1;
		b = -1;
		do
		{
			while (row[++a]) {}
			while (column[++b]) {}
			if (a == size || b == size) break;
			*placement_end++ = MARK(COMBINE(a, b), 4);
		} while (1);
		
		if (!dd[99])
		{
			if (!sd[0])
			{
				*placement_end++ = MIDIAG(0, 99);
			}
			else if (!sd[size - 1 << 1])
			{
				*placement_end++ = MIDIAG(size - 1 << 1, 99);
			}
			else
			{
				*freed_end++ = 99;
			}
		}
		for (i = 2; i < size; i += 2)
		{
			if (!dd[99 + i])
			{
				*freed_end++ = 99 + i;
			}
			if (!dd[99 - i])
			{
				*freed_end++ = 99 - i;
			}
			if (freed_place != freed_end && !sd[a = i])
			{
				*placement_end++ = MIDIAG(a, *freed_place);
				++freed_place;
			}
			if (i == size - 1)
			{
				break;
			}
			if (freed_place != freed_end && !sd[a = (size - 1 << 1) - i])
			{
				*placement_end++ = MIDIAG(a, *freed_place);
				++freed_place;
			}
		}
		freed_end = freed_place = freed;
		for (i = 1; i < size; i += 2)
		{
			if (!dd[99 + i])
			{
				*freed_end++ = 99 + i;
			}
			if (!dd[99 - i])
			{
				*freed_end++ = 99 - i;
			}
			if (freed_place != freed_end && !sd[a = i])
			{
				*placement_end++ = MIDIAG(a, *freed_place);
				++freed_place;
			}
			if (i == size - 1)
			{
				break;
			}
			if (freed_place != freed_end && !sd[a = (size - 1 << 1) - i])
			{
				*placement_end++ = MIDIAG(a, *freed_place);
				++freed_place;
			}
		}
		
		unsigned short int np[100] = {};
		uint32_t *pp, replacement[324],
		 *replacement_end = placement_end - placement + replacement;
		pp = placement;
		while (pp != placement_end)
		{
#ifdef TESTING
			printf("Record: %lX\n", (unsigned long int)*pp);
#endif
			np[*pp++ & 0xFF]++;
		}
		for (i = 1; i != 100; i++)
		{
			np[i] += np[i - 1];
		}
		pp = placement;
		while (pp != placement_end)
		{
			replacement[--np[*pp & 0xFF]] = *pp;
			pp++;
		}
		
		for (i = 0; i != 100; i++)
		{
			np[i] = 0;
		}
		pp = replacement;
		while (pp != replacement_end)
		{
#ifdef TESTING
			printf("!Record: %lX\n", (unsigned long int)*pp);
#endif
			np[*pp++ >> 8 & 0xFF]++;
		}
		for (i = 1; i != 100; i++)
		{
			np[i] += np[i - 1];
		}
		pp = replacement;
		while (pp != replacement_end)
		{
			placement[--np[*pp >> 8 & 0xFF]] = *pp;
			pp++;
		}
		
		pp = placement;
		t = 0;
		a = 0;
		b = 65535;
		p = 0;
		while (pp != placement_end)
		{
			if (*pp >> 18)
			{
				a = UNMARK(*pp);
				t += a != b;
				b = a;
			}
			p += 1 + (*pp >> 16 == 3);
			pp++;
		}
		
		printf("Case #%u: %u %u\n", case_no + 1, p, t);
#ifdef TESTING
		for (pp = placement; pp != placement_end; pp++)
		{
#ifdef TESTING
			printf("*Final Record: %lX\n", (unsigned long int)*pp);
#endif
		}
#endif
		pp = placement;
		*placement_end = 65535;
		while (pp != placement_end)
		{
#ifdef TESTING
			printf("Final Record: %lX\n", (unsigned long int)*pp);
#endif
			if (UNMARK(pp[0]) == UNMARK(pp[1]))
			{
#ifdef TESTING
			printf("Final Record: %lX\n", (unsigned long int)pp[1]);
#endif
				printf("o %u %u\n",
				 (*pp >> 8 & 0xFF) + 1, (*pp & 0xFF) + 1);
				pp++;
			}
			else if (*pp >> 18)
			{
				printf("%c %u %u\n", *pp & 0x10000 ? '+' : 'x',
				 (*pp >> 8 & 0xFF) + 1, (*pp & 0xFF) + 1);
			}
			pp++;
		}
	}
	return 0;
}
