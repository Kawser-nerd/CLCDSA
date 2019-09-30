using System;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Text;

namespace task3
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader reader = null;
            TextWriter writer = null;
            try
            {
                reader = new StreamReader(args[0], Encoding.ASCII);
                writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII);
                var cases = int.Parse(reader.ReadLine());
                Console.WriteLine("Cases {0}", cases);
                for (var i = 1; i <= cases; ++i)
                {
                    var parameters = reader.ReadLine().Split(new[] { ' ' });
                    var rows = int.Parse(parameters[0]);
                    var colums = int.Parse(parameters[1]);
                    var m = int.Parse(parameters[2]);
                    char[,] result;
                    if (rows < colums)
                    {
                        result = MakeGrid(colums, rows, m);
                        if (result != null)
                        {
                            result = Transpose(result);
                        }
                    }
                    else
                    {
                        result = MakeGrid(rows, colums, m);
                    }
                    //var @case = String.Format(CultureInfo.InvariantCulture, "Case #{0}: ({1}x{2} {3} {4})"
                    //    , i, rows, colums, m, rows * colums - m);
                    var @case = String.Format(CultureInfo.InvariantCulture, "Case #{0}:", i);
                    writer.WriteLine(@case);
                    if (result != null)
                    {
                        result[0, 0] = 'c';
                        for (var j = 0; j < rows; ++j)
                        {
                            var sb = new StringBuilder();
                            for (var k = 0; k < colums; ++k)
                            {
                                sb.Append(result[j, k]);
                            }
                            writer.WriteLine(sb.ToString());
                        }
                    }
                    else
                    {
                        writer.WriteLine("Impossible");
                    }
                }
            }
            finally
            {
                if (writer != null)
                    writer.Close();
                if (reader != null)
                    reader.Close();
            }
        }

        private static char[,] MakeGrid(int rows, int columns, int m)
        {
            Debug.Assert(rows >= columns);
            var result = new Lazy<char[,]>(() =>
            {
                var r = new char[rows, columns];
                for (var i = 0; i < rows; ++i)
                {
                    for (var j = 0; j < columns; ++j)
                    {
                        r[i, j] = '*';
                    }
                }
                return r;
            });
            var free = rows * columns - m; // число свободных
            if (free == 1)
            {
                // одну клетку можем открыть всегда
                result.Value[0, 0] = '.';
                return result.Value;
            }

            // Если у нас одна колонка, то все в нее
            if (columns == 1)
            {
                var res = result.Value;
                for (var i = 0; i < free; ++i)
                {
                    res[i, 0] = '.';
                }
                return res;
            }

            // перебираем по числу строк, в которые вписывается свободное пространство
            for (var r = rows; r > 1; --r)
            {
                int partial;
                var fullColumns = Math.DivRem(free, r, out partial);
                var allColumns = fullColumns;
                if (partial > 0)
                {
                    ++allColumns;
                }
                if (allColumns > columns)
                {
                    // нужно больше колонок, чем есть. Увы, конфигурация невпихуема
                    return null;
                }
                var beforePartialColumnRows = r; // число заполняемых строчек в колонке, которая идет до недозаполненной (последней)
                switch (allColumns)
                {
                    case 1:
                        // одну колонку мы уже обработали ранее
                        continue;
                    case 2:
                        // две колонки можно впихнуть, только если вторая колонка полная
                        if (partial != 0)
                        {
                            continue;
                        }
                        break;
                    case 3:
                        // тут мы не можем перенести ничего из 2-ой колонки, не сломав первую,
                        // поэтому такая конфигурация возможна, только если в 3-ей > 1 поля
                        if (partial == 1)
                        {
                            continue;
                        }
                        break;
                    default:
                        // когда колонок > 3, мы можем при необходимости перенести из предпоследней
                        // в последнюю 1 элеменет при условии, что строчек > 2
                        if (partial == 1)
                        {
                            if (r == 2)
                            {
                                continue;
                            }
                            // заимствуем один элемент из предпоследней
                            // и переносим его в последнюю
                            --beforePartialColumnRows;
                            ++partial;
                        }
                        break;
                }
                var res = result.Value;
                // сначала заполняем полные колонки
                for (var i = 0; i < fullColumns - 1; ++i)
                {
                    for (var j = 0; j < r; ++j)
                    {
                        res[j, i] = '.';
                    }
                }
                // потом предпоследнюю
                for (var i = 0; i < beforePartialColumnRows; ++i)
                {
                    res[i, fullColumns - 1] = '.';
                }
                // потом последенюю неполную, если она есть
                for (var i = 0; i < partial; ++i)
                {
                    res[i, fullColumns] = '.';
                }
                return res;
            }
            return null;
        }

        private static char[,] Transpose(char[,] arr)
        {
            var r = arr.GetLength(0);
            var c = arr.GetLength(1);
            var result = new char[c, r];
            for (var i = 0; i < r; ++i)
            {
                for (var j = 0; j < c; ++j)
                {
                    result[j, i] = arr[i, j];
                }
            }
            return result;
        }
    }
}
