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
        Reader sr = new Reader("C:\\test\\in.in");
        StreamWriter sw = new StreamWriter("C:\\test\\out.out");
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

  

    static string Solution(Reader sr)
    {
        int n = int.Parse(sr.ReadLine());
        int[] a = new int[n];
        int[] b = new int[n];
        {
            string[] t = sr.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(t[i]);
            } 
            t = sr.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                b[i] = int.Parse(t[i]);
            }
        }
        int[] res = new int[n];
        int c = 1;

        bool[] allowed = new bool[n];
        for (int i = 0; i < n; i++)
        {
            allowed[i] = true;
        }
        int[] ma = new int[n];
        int[] mb = new int[n];
        for (int i = 0; i < n; i++)
        {
            ma[i] = mb[i] = 1;
        }

        while (c <= n)
        {
            int pos = -1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == ma[i] && b[i] == mb[i] && allowed[i])
                {
                    if (pos == -1)
                    {
                        pos = i;
                        //break;
                    }
                    else
                    {
                        if (a[i] == a[pos])
                            pos = i;
                    }
                }
            }
            allowed[pos] = false;

            res[pos] = c++;

            for (int i = pos+1; i < n; i++)
            {
                ma[i] = Math.Max(ma[i], a[pos]+1);
                if(allowed[i] && ma[i]> a[i])
                     throw new Exception("error");
            }
            for (int i = 0; i < pos; i++)
            {
                mb[i] = Math.Max(mb[i], b[pos] + 1);
                if (allowed[i] && mb[i] > b[i])
                    throw new Exception("error");
            }

        }



        string sres = "";
        for (int i = 0; i < n; i++)
        {
            sres += " " + res[i];
        }
        return sres.Substring(1);
    }
}
