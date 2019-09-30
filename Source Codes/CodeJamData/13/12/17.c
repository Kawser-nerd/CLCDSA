//Compile with -lglpk

#include <stdio.h>
#include <glpk.h>

int main() {

	int i,t,T;
	int E,R,N,v,ind[4]={0},r;
	double vars[4]={0};
	glp_term_out(GLP_OFF);

	scanf("%d", &T);

	for(t=1;t<=T;t++) {

		scanf("%d%d%d", &E, &R, &N);

		glp_prob *ip = glp_create_prob();
		glp_set_obj_dir(ip, GLP_MAX);

		glp_add_cols(ip, 2*N);
		glp_add_rows(ip, 2*N);

		for(i=1;i<=N;i++) {
			scanf("%d", &v);
			glp_set_obj_coef(ip, i, v);
			glp_set_col_kind(ip, i, GLP_IV);
			glp_set_col_bnds(ip, i, GLP_DB, 0, E);
		}

		for(i=N+1;i<=2*N;i++) {
			glp_set_obj_coef(ip, i, 0);
			glp_set_col_kind(ip, i, GLP_IV);
			glp_set_col_bnds(ip, i, GLP_DB, 0, E);
		}

		for(i=1;i<=N;i++) {
			if(i==1) {
				ind[1]=1;
				vars[1]=1;
				glp_set_mat_row(ip, i, 1, ind, vars);
				glp_set_row_bnds(ip, i, GLP_DB, 0, E);
			}
			else {
				ind[1]=i;
				ind[2]=N+i-1;
				vars[1]=-1;
				vars[2]=1;
				glp_set_mat_row(ip, i, 2, ind, vars);
				glp_set_row_bnds(ip, i, GLP_LO, 0, 0);
			}
		}

		for(i=1;i<=N;i++) {
			if(i==1) {
				ind[1]=1;
				ind[2]=N+1;
				vars[1]=1;
				vars[2]=1;
				glp_set_mat_row(ip, N+1, 2, ind, vars);
				glp_set_row_bnds(ip, N+1, GLP_UP, 0, E+R);
			}
			else {
				ind[1]=N+i-1;
				ind[2]=i;
				ind[3]=N+i;
				vars[1]=-1;
				vars[2]=1;
				vars[3]=1;
				glp_set_mat_row(ip, N+i, 3, ind, vars);
				glp_set_row_bnds(ip, N+i, GLP_UP, 0, R);
			}
		}

		glp_simplex(ip, NULL);
		glp_intopt(ip, NULL);
		r = glp_mip_status(ip);
		if(r==GLP_OPT) printf("Case #%d: %lld\n", t, (long long int)glp_get_obj_val(ip));
		else printf("Case #%d: failed!\n", t);
		glp_delete_prob(ip);
	}

	return 0;
}
