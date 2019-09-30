import java.util.*;
import java.io.*;

/*
   AtCoder contest
   coder : yoichidon
 */

class Matrix{
    int row, column;
    long[][] mat;//long[r][c]

    public Matrix(int r, int c){
        this.row = r;
        this.column = c;
        this.mat = new long[row][column];
    }
    public Matrix(long[][] mat){
        this.mat = mat;
        this.row = mat.length;
        this.column = mat[0].length;
    }

    int getRow(){
        return row;
    }
    int getColumn(){
        return column;
    }
    long get(int r, int c){
        return mat[r][c];
    }
    void set(int r, int c, long value){
        mat[r][c] = value;
    }
    Matrix copy(){
        Matrix ans = new Matrix(row, column);
        for(int r=0; r<row; r++) for(int c=0; c<column; c++) ans.set(r,c, mat[r][c]);
        return ans;
    }



    static long scalarPlus(long x, long y){
        return x^y;
    }
    static long scalarMinus(long x, long y){
        return scalarPlus(x, -y);
    }
    static long scalarMult(long x, long y){
        return x&y;
    }



    Matrix add(Matrix another){
        assert this.getRow()==another.getRow() && this.getColumn()==another.getColumn();
        Matrix ans = new Matrix(row, column);
        for(int r=0; r<row; r++) for(int c=0; c<column; c++){
            ans.set(r,c, scalarPlus(this.get(r,c), another.get(r,c)));
        }
        return ans;
    }
    Matrix sub(Matrix another){
        assert this.getRow()==another.getRow() && this.getColumn()==another.getColumn();
        Matrix ans = new Matrix(row, column);
        for(int r=0; r<row; r++) for(int c=0; c<column; c++){
            ans.set(r,c, scalarMinus(this.get(r,c), another.get(r,c)));
        }
        return ans;
    }

    static Matrix identity(int n){
        Matrix M = new Matrix(n,n);
        for(int i=0; i<n; i++) M.set(i,i,Long.MAX_VALUE);
        return M;
    }



    Matrix mult(long scalar){
        Matrix ans = new Matrix(row, column);
        for(int r=0; r<row; r++) for(int c=0; c<column; c++) ans.set(r,c, scalarMult(this.get(r,c), scalar));
        return ans;
    }
    long[] mult(long[] vector){
        assert column == vector.length;
        long[] ans = new long[row];
        for(int r=0; r<row; r++){
            for(int c=0; c<column; c++) ans[r] = scalarPlus(ans[r], scalarMult(mat[r][c], vector[c]));
        }
        return ans;
    }
    Matrix mult(Matrix another){
        assert this.getColumn() == another.getRow();
        Matrix ans = new Matrix(this.getRow(), another.getColumn());
        for(int r=0; r<this.getRow(); r++) for(int c=0; c<another.getColumn(); c++){
            for(int k=0; k<this.getColumn(); k++){
                ans.set(r,c, scalarPlus(ans.get(r,c), scalarMult(this.get(r,k), another.get(k,c))));
            }
        }
        return ans;
    }

    Matrix power(long p){
        assert row==column;
        assert p>=0;
        if(p==0) return Matrix.identity(row);
        if(p==1) return this.copy();
        if(p%2==0){
            Matrix H = this.power(p/2);
            return H.mult(H);
        }else{
            Matrix M = this.power(p-1);
            return this.mult(M);
        }



    }

    long trace(){
        long tr = 0;
        assert row==column;
        for(int i=0; i<row; i++) tr += mat[i][i];
        return tr;
    }

    public String toString(){
        return Arrays.deepToString(mat);
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        long M = sc.nextLong();

        long[] A = new long[K];
        for(int k=0; k<K; k++)  A[K-1-k]=sc.nextLong();

        Matrix rec = new Matrix(K,K);
        for(int k=0; k<K; k++) rec.set(0,k, sc.nextLong());
        for(int k=0; k<K-1; k++) rec.set(k+1, k, Long.MAX_VALUE);

        Matrix P = rec.power(M-1);


        System.out.println(P.mult(A)[K-1]);


    }
}