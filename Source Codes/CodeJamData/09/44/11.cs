using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Collections.Generic;
using System.Text;

namespace CodeJam2
{
    class Program
    {
        static void Main(string[] args)
        {
            var temp = GetOuterCircle(new Vector3(-1, 0, 1), new Vector3(1, 0, 1), new Vector3(0, 1, 1));
            //CrazyRows();
            WateringPlantsSimple();
        }

        static double DistXY(Vector3 v1, Vector3 v2)
        {
            return Math.Sqrt((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y));
        }

        static void WateringPlantsSimple()
        {
            int cases = int.Parse(Console.ReadLine());
            for (int rep = 0; rep < cases; rep++)
            {
                int n = int.Parse(Console.ReadLine());
                IList<Vector3> circles = new List<Vector3>();
                for (int i = 0; i < n; i++)
                {
                    var s = Console.ReadLine().Split(' ');
                    Vector3 circle = new Vector3(double.Parse(s[0]), double.Parse(s[1]), double.Parse(s[2]));
                    circles.Add(circle);
                }
                circles = circles.OrderByDescending(p => p.z).ToList();
                for (int i = circles.Count - 1; i >= 1; i--)
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (DistXY(circles[i], circles[j]) + circles[i].z < circles[j].z)
                        {
                            circles.RemoveAt(i);
                            break;
                        }
                    }
                }
                Console.WriteLine("Case #{0}: {1}", rep + 1, Solve(circles));
            }
        }

        private static double Solve(IList<Vector3> circles)
        {
            if (circles.Count == 1) return circles[0].z;
            if (circles.Count == 2) return Math.Max(circles[0].z, circles[1].z);

            double rbest = 1e10;
            for (int i = 0; i < 3; i++)
            {
                double ri = circles[i].z;
                int j = (i + 1)%3;
                int k = (i + 2)%3;
                double re = (circles[j].z + circles[k].z + DistXY(circles[j], circles[k]))/2;
                double r = Math.Max(ri, re);
                if (r < rbest) rbest = r;
            }
            return rbest;
        }

        static Vector3 GetOuterCircle(Vector3 c1, Vector3 c2, Vector3 c3)
        {
            Vector3 result = new Vector3();

            Matrix3x3 A = new Matrix3x3();
            Vector3 b = new Vector3();

            A[0, 0] = c1[0] - c2[0];
            A[0, 1] = c1[1] - c2[1];
            A[0, 2] = -(c1[2] - c2[2]);
            b[0] = (c1[2] * c1[2] - c2[2] * c2[2]) - (c1[0] * c1[0] - c2[0] * c2[0]) - (c1[1] * c1[1] - c2[1] * c2[1]) / 2;
            A[1, 0] = c1[0] - c3[0];
            A[1, 1] = c1[1] - c3[1];
            A[1, 2] = -(c1[2] - c3[2]);
            b[1] = (c1[2] * c1[2] - c3[2] * c3[2]) - (c1[0] * c1[0] - c3[0] * c3[0]) - (c1[1] * c1[1] - c3[1] * c3[1]) / 2;
            A[2, 0] = c2[0] - c3[0];
            A[2, 1] = c2[1] - c3[1];
            A[2, 2] = -(c2[2] - c3[2]);
            b[2] = (c2[2] * c2[2] - c3[2] * c3[2]) - (c2[0] * c2[0] - c3[0] * c3[0]) - (c2[1] * c2[1] - c3[1] * c3[1]) / 2;
            if (Matrix3x3.SolveEquations(out result, A, b) == 1)
            {
                return null;
            }

            return result;
        }

        static void WateringPlants()
        {

        }

        static void CrazyRows()
        {
            int cases = int.Parse(Console.ReadLine());
            for (int rep = 0; rep < cases; rep++)
            {
                int n = int.Parse(Console.ReadLine());
                int[] x = new int[n];
                for (int i = 0; i < n; i++)
                {
                    x[i] = Console.ReadLine().LastIndexOf('1');
                }

                int result = 0;
                for (int i = 0; i < n; i++)
                {
                    if (x[i] > i)
                    {
                        int j;
                        for (j = i + 1; j < n; j++)
                        {
                            if (x[j] <= i)
                            {
                                break;
                            }
                        }
                        int temp = x[j];
                        for (int k = j; k > i; k--)
                        {
                            x[k] = x[k - 1];
                            result++;
                        }
                        x[i] = temp;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", rep + 1, result);
            }
        }
    }

    // http://www.codeproject.com/KB/cs/LinearEquationsSystemSoln.aspx
    // --------------------------------------------------------
    // Matrix3x3.cs
    //
    // Author: Vit Buchta
    // Date  : June 25, 2007
    // --------------------------------------------------------

    /// <summary>
    /// Square real matrix having 3 rows and 3 columns
    /// </summary>
    public class Matrix3x3
    {
        double[,] A = new double[3, 3];

        /// <summary>
        /// A constructor. It sets diagonal matrix elements to 1.
        /// </summary>
        public Matrix3x3()
        {
            A[0, 0] = A[1, 1] = A[2, 2] = 1;
        }

        /// <summary>
        /// A constructor setting all matrix elements to a given real number.
        /// </summary>
        /// <param name="q">A number to which all matriex elements are to be set.</param>
        public Matrix3x3(double q)
        {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    A[i, j] = q;
        }

        /// <summary>
        /// A copy constructor copying a matrix X into a new matrix.
        /// </summary>
        /// <param name="X">The matrix which will be copied.</param>
        public Matrix3x3(Matrix3x3 X)
        {
            this.Copy(X);
        }

        /// <summary>
        /// Indexer. It select a matrix element in i-th row and j-th column.
        /// </summary>
        /// <param name="i">Zero-based row index.</param>
        /// <param name="j">Zero-based column index.</param>
        /// <returns>An element in i-th row and j-th column.</returns>
        public double this[int i, int j]
        {
            get
            {
                if (!((i < 0 || i >= 3) && (j < 0 || j <= 3)))
                    return A[i, j];
                else
                    return 0;
            }

            set
            {
                if (!((i < 0 || i >= 3) && (j < 0 || j <= 3)))
                    A[i, j] = value;
            }
        }

        /// <summary>
        /// Provides a copy of marix X.
        /// </summary>
        /// <param name="X">A matrix which will be copied.</param>
        public void Copy(Matrix3x3 X)
        {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    this[i, j] = X[i, j];
        }

        /// <summary>
        /// Calculates the value of determinant.
        /// </summary>
        /// <returns>Determinant value.</returns>
        public double Determinant()
        {
            double d = 0;
            d += A[0, 0] * (A[1, 1] * A[2, 2] - A[1, 2] * A[2, 1]);
            d -= A[0, 1] * (A[1, 0] * A[2, 2] - A[1, 2] * A[2, 0]);
            d += A[0, 2] * (A[1, 0] * A[2, 1] - A[1, 1] * A[2, 0]);

            return d;
        }

        /// <summary>
        /// Addition of two matrixes.
        /// </summary>
        /// <param name="A">First matrix to be added.</param>
        /// <param name="B">Second matrix to be added.</param>
        /// <returns>Matrix obtained as A + B.</returns>
        public static Matrix3x3 operator +(Matrix3x3 A, Matrix3x3 B)
        {
            Matrix3x3 C = new Matrix3x3();
            for (int i = 0; i <= 2; i++)
                for (int j = 0; j <= 2; j++)
                    C[i, j] = A[i, j] + B[i, j];

            return C;
        }

        /// <summary>
        /// Matrix substraction.
        /// </summary>
        /// <param name="A">First matrix.</param>
        /// <param name="B">Matrix to be substracted.</param>
        /// <returns>Matrix obtained as A - B.</returns>
        public static Matrix3x3 operator -(Matrix3x3 A, Matrix3x3 B)
        {
            Matrix3x3 C = new Matrix3x3();
            for (int i = 0; i <= 2; i++)
                for (int j = 0; j <= 2; j++)
                    C[i, j] = A[i, j] - B[i, j];

            return C;
        }

        /// <summary>
        /// Change a column by a given vector.
        /// </summary>
        /// <param name="R">Resulting matrix</param>
        /// <param name="A">Given matrix</param>
        /// <param name="b">A vector</param>
        /// <param name="j">Zero-based index of a columnd to be substitued by vector b.</param>
        /// <returns>A matrix having substitued j-th column by vector b.</returns>
        public static int ChangeColumn(out Matrix3x3 R, Matrix3x3 A, Vector3 b, int j)
        {
            R = new Matrix3x3();
            R.Copy(A);

            if (j < 0 || j >= 3)
                return 1;

            R[0, j] = b[0];
            R[1, j] = b[1];
            R[2, j] = b[2];

            return 0;
        }

        /// <summary>
        /// Solve a set of linear equations by the determinant method.
        /// </summary>
        /// <param name="x">Solution vector.</param>
        /// <param name="A">Matrix of coefficients.</param>
        /// <param name="b">Right-side vector.</param>
        /// <returns>Error value. O means OK, other stands for error.</returns>
        public static int SolveEquations(out Vector3 x, Matrix3x3 A, Vector3 b)
        {
            x = new Vector3();
            const double eps = 1.0E-12;
            double d = A.Determinant();
            if (Math.Abs(d) < eps)
                return 1;

            Matrix3x3 M0 = new Matrix3x3();
            Matrix3x3 M1 = new Matrix3x3();
            Matrix3x3 M2 = new Matrix3x3();

            ChangeColumn(out M0, A, b, 0);
            ChangeColumn(out M1, A, b, 1);
            ChangeColumn(out M2, A, b, 2);

            x[0] = M0.Determinant() / d;
            x[1] = M1.Determinant() / d;
            x[2] = M2.Determinant() / d;

            return 0;
        }

        /// <summary>
        /// Matrix by vector mutiplication.
        /// </summary>
        /// <param name="A">A matrix.</param>
        /// <param name="b">A vector</param>
        /// <returns>Matrix obtained as A times b.</returns>
        public static Vector3 operator *(Matrix3x3 A, Vector3 b)
        {
            Vector3 r = new Vector3(0);
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    r[i] += A[i, j] * b[j];

            return r;
        }
    }
    /// <summary>
    /// Vector with 3 elements
    /// </summary>
    public class Vector3
    {
        double[] v = new double[3];

        /// <summary>
        /// A constructor setting all three vector elements to 1.
        /// </summary>
        public Vector3()
        {
            v[0] = v[1] = v[2] = 1;
        }

        /// <summary>
        /// A contructor which sets the vector elements to given numbers.
        /// </summary>
        /// <param name="x">First vector element</param>
        /// <param name="y">Second element</param>
        /// <param name="z">Third element</param>
        public Vector3(double x, double y, double z)
        {
            v[0] = x;
            v[1] = y;
            v[2] = z;
        }

        /// <summary>
        /// A constructor setting all three elements to a given number
        /// </summary>
        /// <param name="q">A value to be assigned to all three vector elements.</param>
        public Vector3(double q)
        {
            v[0] = v[1] = v[2] = q;
        }

        /// <summary>
        /// A copy constuctor.
        /// </summary>
        /// <param name="x">This vector will be copied into a newly created vector.</param>
        public Vector3(Vector3 x)
        {
            this.Copy(x);
        }

        /// <summary>
        /// An approach to the first vector component.
        /// </summary>
        public double x
        {
            get { return v[0]; }
            set { v[0] = value; }
        }

        /// <summary>
        /// An approach to the second vector component.
        /// </summary>
        public double y
        {
            get { return v[1]; }
            set { v[1] = value; }
        }

        /// <summary>
        /// An approach to the third vector component.
        /// </summary>
        public double z
        {
            get { return v[2]; }
            set { v[2] = value; }
        }

        /// <summary>
        /// An indexer providing an approach to distict vector components.
        /// </summary>
        /// <param name="i">Zero-based index of vector component.</param>
        /// <returns>i-th vector component.</returns>
        public double this[int i]
        {
            get
            {
                if (i < 0 || i >= 3)
                    return 0;
                else
                    return v[i];
            }

            set
            {
                if (!(i < 0 || i >= 3))
                    v[i] = value;
            }
        }

        /// <summary>
        /// Copies a givien vector into this vector.
        /// </summary>
        /// <param name="x">A vector to be copied.</param>
        public void Copy(Vector3 x)
        {
            for (int i = 0; i < 3; i++)
                this.v[i] = x.v[i];
        }

        /// <summary>
        /// Multiplication of a real number and a vector. 
        /// </summary>
        /// <param name="q">A real number.</param>
        /// <param name="a">A vector.</param>
        /// <returns>A resulting vector defined as q times a.</returns>
        public static Vector3 operator *(double q, Vector3 a)
        {
            Vector3 r = new Vector3();
            for (int i = 0; i < 3; i++)
            {
                r[i] = q * a[i];
            }

            return r;
        }

        /// <summary>
        /// Multiplication of a real number and a vector. 
        /// </summary>
        /// <param name="a">A vector.</param>
        /// <param name="q">A real number.</param>
        /// <returns>A resulting vector defined as q times a.</returns>
        public static Vector3 operator *(Vector3 a, double q)
        {
            Vector3 r = new Vector3();
            for (int i = 0; i < 3; i++)
            {
                r[i] = q * a[i];
            }

            return r;
        }

        /// <summary>
        /// Vector addition
        /// </summary>
        /// <param name="a">First vector</param>
        /// <param name="b">Second vector</param>
        /// <returns>Resulting vector defined as a + b.</returns>
        public static Vector3 operator +(Vector3 a, Vector3 b)
        {
            Vector3 r = new Vector3();
            r[0] = a[0] + b[0];
            r[1] = a[1] + b[1];
            r[2] = a[2] + b[2];

            return r;
        }

        /// <summary>
        /// Vector substraction
        /// </summary>
        /// <param name="a">First vector</param>
        /// <param name="b">Second vector</param>
        /// <returns>Resulting vector defined as a - b.</returns>
        public static Vector3 operator -(Vector3 a, Vector3 b)
        {
            Vector3 r = new Vector3();
            r[0] = a[0] - b[0];
            r[1] = a[1] - b[1];
            r[2] = a[2] - b[2];

            return r;
        }

        /// <summary>
        /// Dot product of two vectors.
        /// </summary>
        /// <param name="a">First vector.</param>
        /// <param name="b">Second vector.</param>
        /// <returns>Resulting vector</returns>
        public static double DotProduct(Vector3 a, Vector3 b)
        {
            double r = 0;
            for (int i = 0; i < 3; i++)
            {
                r += a[i] * b[i];
            }

            return r;
        }

        /// <summary>
        /// Dot product of two vectors.
        /// </summary>
        /// <param name="a">First vector.</param>
        /// <param name="b">Second vector.</param>
        /// <returns>Resulting vector</returns>
        public static double operator *(Vector3 a, Vector3 b)
        {
            return DotProduct(a, b);
        }

        /// <summary>
        /// Coross product of two vectors.
        /// </summary>
        /// <param name="a">First vector.</param>
        /// <param name="b">Second vector.</param>
        /// <returns>Resulting vector</returns>
        public static Vector3 CrossProduct(Vector3 a, Vector3 b)
        {
            Vector3 r = new Vector3();
            r.x = a.y * b.z - a.z * b.y;
            r.y = a.z * b.x - a.x * b.z;
            r.z = a.x * b.y - a.y * b.x;

            return r;
        }
    }
}