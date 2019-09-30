using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



#region Hide
static public class Serializer
{
    static public void SerializeObject(string filename, object

objectToSerialize)
    {
        Stream stream = File.Open(filename, FileMode.Create);
        BinaryFormatter bFormatter = new BinaryFormatter();
        bFormatter.Serialize(stream, objectToSerialize);
        stream.Close();
    }

    static public object DeSerializeObject(string filename)
    {
        object objectToSerialize;
        Stream stream = File.Open(filename, FileMode.Open);
        BinaryFormatter bFormatter = new BinaryFormatter();
        objectToSerialize =
           (object)bFormatter.Deserialize(stream);
        stream.Close();
        return objectToSerialize;
    }
}

class Reader : System.IO.StreamReader
{


    public Reader(string path) : base(path) { }

    public int ReadInt()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        int r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public long ReadLong()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        long r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public char ReadChar()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        return (char)this.Read();
    }
    public string ReadWord()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        while (!this.EndOfStream && char.IsWhiteSpace((char)this.Peek()))
        {
            this.Read();
        }
        StringBuilder sb = new StringBuilder();

        while (!this.EndOfStream && !char.IsWhiteSpace((char)this.Peek()))
        {
            sb.Append((char)this.Read());
        }
        return sb.ToString();
    }
}
#endregion


class Program
{

    static void Main(string[] args)
    {
        Reader sr = new Reader("F:\\test\\in.in");
        StreamWriter sw = new StreamWriter("F:\\test\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }
    class FF : IComparable<FF>
    {
        public int F, T;

        #region IComparable<FF> Members

        int IComparable<FF>.CompareTo(FF other)
        {
            if (F == other.F)
                return T.CompareTo(other.T);
            return F.CompareTo(other.F);
        }

        #endregion
    }



    class TT:IComparable<TT>
    {
        public int freedom;
        public List<int> Inside;
        public bool[] B;
        #region IComparable<TT> Members

        int IComparable<TT>.CompareTo(TT other)
        {
            return freedom.CompareTo(other.freedom);
        }

        #endregion
    }



    static string Solution(Reader sr)
    {
        string[] t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        int N = int.Parse(t[0]);
        int M = int.Parse(t[1]);

        FF[] G = new FF[M];
        t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        for (int i = 0; i < M; i++)
        {
            G[i] = new FF();
            G[i].F = int.Parse(t[i]);
        }
        t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        for (int i = 0; i < M; i++)
        {
            G[i].T = int.Parse(t[i]);
        }
        int min = int.MaxValue;
        for (int i = 0; i < M; i++)
        {
            int k = G[i].T - G[i].F;
            min = Math.Min(k, min);
            min = Math.Min(N - k, min);
        }
        Array.Sort(G);
        List<List<int>> H = new List<List<int>>();
        List<int> bb = new List<int>();
        for (int i = 0; i < N; i++)
        {
            bb.Add(i);
        }
        H.Add(bb);
        for (int i = 0; i < M; i++)
        {
            List<List<int>> QQ = new List<List<int>>();
            int from = G[i].F;
            int to = G[i].T;
            foreach (var item in H)
            {
                List<int> A = new List<int>();
                List<int> B = new List<int>();
                bool qq = true;
                foreach (var cc in item)
                {
                    if (qq)
                    {
                        A.Add(cc);
                        if (cc == from)
                        {
                            B.Add(cc);
                            qq = false;
                        }
                    }
                    else
                    {
                        B.Add(cc);
                        if (cc == to)
                        {
                            A.Add(cc);
                            qq = true;
                        }
                    }
                }
                if (A.Count > 2)
                    QQ.Add(A);
                if (B.Count > 2)
                    QQ.Add(B);
            }
            H = QQ;
        }

        List<TT> rooms = new List<TT>();
        List<int>[] poles = new List<int>[N];
        int[] res = new int[N];
        for (int i = 0; i < N; i++)
        {
            poles[i] = new List<int>();
        }

        for (int i = 0; i < H.Count; i++)
        {
            rooms.Add(new TT());
            rooms[i].freedom = H[i].Count;
            rooms[i].Inside = H[i];
            rooms[i].B = new bool[min];
            foreach (var item in H[i])
            {
                poles[item].Add(i);
            }
        }

        rooms.Sort();
        while (rooms.Count>0&&rooms[rooms.Count - 1].freedom != 0)
        {
            int w = 0;
            while (rooms[w].freedom == 0) w++;
            int k=-1;
            foreach (var item in rooms[w].Inside)
            {
                if (res[item] == 0)
                {
                    k = item;
                    break;
                }
            }
            int c = 0;
            while (c < min && !rooms[w].B[c]) { c++; }
            if (c == min)
                c--;
            foreach (var item in poles[k])
            {
                rooms[item].B[c] = true;
                rooms[item].freedom--;
            }
            res[k] = c + 1;
            rooms.Sort();
        }
        string g = res.Length.ToString() + "\r\n";
        string sss = "";
        foreach (var item in res)
        {
            sss += " " + item.ToString();
        }
        return g+sss.Substring(1);

    }
}
