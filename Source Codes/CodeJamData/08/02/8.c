#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	FILE			*in;
	FILE			*out;
    unsigned int    num_cases;
    unsigned int    cur_case;
    unsigned int    na;
    unsigned int    nb;
    unsigned int    a;
    unsigned int    b;
    unsigned int    t;
    unsigned int    i;
    unsigned int    hd;
    unsigned int    md;
    unsigned int    ha;
    unsigned int    ma;
    unsigned int    *ad;
    unsigned int    *aa;
    unsigned int    *bd;
    unsigned int    *ba;
    unsigned int    sa;
    unsigned int    sb;

	if(argc < 3)
		return 0;

	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	if(!in || !out)
	{
		if(in)
			fclose(in);
		if(out)
			fclose(out);
		return 0;
	}

    fscanf(in, "%u\n", &num_cases);

	for(cur_case = 0; cur_case < num_cases; cur_case++)
	{
        fscanf(in, "%u\n", &t);
        fscanf(in, "%u %u\n", &na, &nb);

        ad = (unsigned int*)malloc(na * sizeof(unsigned int));
        aa = (unsigned int*)malloc(na * sizeof(unsigned int));
        bd = (unsigned int*)malloc(nb * sizeof(unsigned int));
        ba = (unsigned int*)malloc(nb * sizeof(unsigned int));

        if(!ad || !aa || !bd || !ba)
        {
            printf("malloc error\n");
            return 0;
        }

        for(a = 0; a < na; a++)
		{
            fscanf(in, "%u:%u %u:%u\n", &hd, &md, &ha, &ma);
            ad[a] = hd * 60 + md;
            aa[a] = ha * 60 + ma;
		}

        for(b = 0; b < nb; b++)
		{
            fscanf(in, "%u:%u %u:%u\n", &hd, &md, &ha, &ma);
            bd[b] = hd * 60 + md;
            ba[b] = ha * 60 + ma;
		}

        for(a = 0; (a + 1) < na; a++)
        {
            md = a;
            ma = a;
            for(i = a + 1; i < na; i++)
            {
                if(ad[i] < ad[md])
                    md = i;
                if(aa[i] < aa[ma])
                    ma = i;
            }
            b = aa[a];
            aa[a] = aa[ma];
            aa[ma] = b;
            b = ad[a];
            ad[a] = ad[md];
            ad[md] = b;
        }

        for(b = 0; (b + 1) < nb; b++)
        {
            md = b;
            ma = b;
            for(i = b + 1; i < nb; i++)
            {
                if(bd[i] < bd[md])
                    md = i;
                if(ba[i] < ba[ma])
                    ma = i;
            }
            a = ba[b];
            ba[b] = ba[ma];
            ba[ma] = a;
            a = bd[b];
            bd[b] = bd[md];
            bd[md] = a;
        }

        sa = 0;
        sb = 0;

        for(a = b = 0; a < na; a++)
        {
            if(b == nb || ad[a] < (ba[b] + t))
                sa++;
            else
                b++;
        }

        for(a = b = 0; b < nb; b++)
        {
            if(a == na || bd[b] < (aa[a] + t))
                sb++;
            else
                a++;
        }

        fprintf(out, "Case #%u: %u %u\n", cur_case + 1, sa, sb);

        free(ad);
        free(aa);
        free(bd);
        free(ba);
	}

	fclose(in);
	fclose(out);
	return 1;
}
