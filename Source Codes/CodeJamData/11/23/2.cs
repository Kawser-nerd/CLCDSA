using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace ConsoleApplication3
{
    class Program
    {

        static string[] _args;
        static void Main(string[] args)
        {
            _args = args;
            OpenFile();

            int testcases = ReadInt();

            for (int icase = 0; icase < testcases; icase++)
            {
                var lc = ReadInts();
                var nv = lc[0];
                var nw = lc[1];
                var sw = ReadInts();
                var ew = ReadInts();


                var allVertex = new List<vertex>();
                var fisrtRoom = new Room();
                for (int i = 0; i < nv; i++)
                {
                    var v = new vertex() { Number = i + 1 };
                    allVertex.Add(v);
                    fisrtRoom.Vertexs.Add(v);
                }

                var rooms = new List<Room>();
                rooms.Add(fisrtRoom);

                for (int i = 0; i < nw; i++)
                    for (int j = 0; j < rooms.Count; j++)
                    {
                        if (rooms[j].Vertexs.Where(k => k.Number == sw[i] || k.Number == ew[i]).Count() == 2)
                        {
                            rooms.Insert(j + 1, SplitRoom(rooms[j], sw[i], ew[i]));
                            break;
                        }
                    }


                var max = rooms.Min(i => i.Vertexs.Count);

                foreach (var r in rooms)
                {
                    var used = new bool[max];
                    foreach (var v in r.Vertexs)
                        if (v.IsDiv)
                        {
                            if (v.value != 0)
                                used[v.value - 1] = true;
                        }

                    for (int u = 0; u < max; u++)
                        if (!used[u])
                        {
                            foreach (var v in r.Vertexs)
                                if (v.IsDiv && v.value == 0)
                                {
                                    v.value = u + 1;
                                    goto ok;
                                }
                            foreach (var v in r.Vertexs)
                                if (v.value == 0)
                                {
                                    v.value = u + 1;
                                    goto ok;
                                }
                            throw new NotImplementedException();
                        ok:;
                        }
                }



                WriteCase(max.ToString());
                string s = string.Empty;
                foreach (var i in allVertex)
                    s += (i.value != 0 ? i.value : 1).ToString()+" ";
                WriteLine(s);

            }


            WriteOutFile();
        }


        class Room
        {
            public List<vertex> Vertexs = new List<vertex>();
        }

        class vertex
        {
            public int Number { get; set; }
            public bool IsDiv { get; set; }
            public int value { get; set; }
        }

        private static Room SplitRoom(Room room, int s, int e)
        {
            if (e < s)
            {
                var d = s;
                s = e;
                e = d;
            }
            var list = room.Vertexs;
            bool hitStart = false;
            var result = new Room();

            for (int i = 0; i < list.Count; )
            {
                if (list[i].Number == s)
                {
                    hitStart = true;
                    result.Vertexs.Add(list[i]);
                    list[i].IsDiv = true;
                    i++;
                }
                else if (list[i].Number == e)
                {
                    hitStart = false;
                    list[i].IsDiv = true;
                    result.Vertexs.Add(list[i]);
                    i++;
                }
                else
                    if (hitStart)
                    {
                        result.Vertexs.Add(list[i]);
                        list.RemoveAt(i);
                    }
                    else
                        i++;
            }

            return result;

        }

        public class GameStatistc
        {
            public int idx { get; set; }
            public int GamesPlayed { get; set; }
            public int GamesWin { get; set; }
            public List<Tuple<int, bool>> Oposes { get; set; }
            public double wp { get; set; }
            public double owp { get; set; }
            public double oowp { get; set; }
        }


        #region Common API for Codejam

        static string[] _readLines;
        static int _currentLine;
        private static void OpenFile()
        {
            _readLines = File.ReadAllLines(_args[0]);
        }

        private static string ReadString()
        {
            return _readLines[_currentLine++];
        }

        private static int[] ReadInts()
        {
            return ReadString().Split(' ').Select(i => int.Parse(i)).ToArray();
        }

        private static long[] ReadLongs()
        {
            return ReadString().Split(' ').Select(i => long.Parse(i)).ToArray();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadString());
        }

        private static string[] ReadStrings()
        {
            return ReadString().Split(' ').ToArray();
        }

        static StringBuilder _outLines = new StringBuilder();
        static int caseNumber;
        private static void WriteCase(string result)
        {
            WriteLine("Case #{0}: {1}", ++caseNumber, result);
        }

        private static void WriteLine(string str, params object[] ps)
        {
            _outLines.AppendFormat(str, ps);
            _outLines.AppendLine();
        }

        private static string StringOfInts(params int[][] ints)
        {
            StringBuilder result = new StringBuilder();
            var allInts =
                from i in ints
                from j in i
                select j.ToString() + " ";

            foreach (var i in allInts)
                result.Append(i);
            return result.ToString().TrimEnd();
        }

        private static void WriteOutFile()
        {
            File.WriteAllText(_args[1], _outLines.ToString());
        }

        #endregion
    }

    #region extends
    public static class Extends
    {
        public static string ToString(this DateTime? This, string format)
        {
            return This == null || This == default(DateTime) ? string.Empty : This.Value.ToString(format);
        }

        public static string ToString(this decimal? value, string format)
        {
            if (value.HasValue)
                return value.Value.ToString(format);
            else
                return string.Empty;
        }

        public static string ToStringNoDefault<TObject>(this TObject value, string format) where TObject : IFormattable
        {
            if (value.Equals(default(TObject)))
                return string.Empty;
            return ((IFormattable)value).ToString(format, null);
        }

        public static string ToStringNoDefault<TObject>(this TObject value)
        {
            if (object.Equals(value, default(TObject)))
                return string.Empty;
            return value.ToString();
        }

        public static bool IsNullOrEmpty(this string value)
        {
            return string.IsNullOrEmpty(value);
        }

        public static bool IsNullOrWhiteSpace(this string value)
        {
            return string.IsNullOrWhiteSpace(value);
        }

        public static bool HasValue(this string value)
        {
            var ws = string.IsNullOrWhiteSpace(value);
            var ne = string.IsNullOrEmpty(value);
            if (ws && ne)
                return false;
            else
                return true;
        }

        public static DateTime? ToNullableDateTime(this string value)
        {
            if (value.IsNullOrEmpty())
                return null;
            return DateTime.Parse(value);
        }

        public static DateTime? ToNullableDateTime(this string value, string format)
        {
            if (value.IsNullOrEmpty())
                return null;
            return DateTime.ParseExact(value, format, null);
        }

        public static short? ToNullableShort(this string value)
        {
            if (value.IsNullOrEmpty())
                return null;
            return short.Parse(value);
        }

        public static decimal? ToNullableDecimal(this string value)
        {
            if (value.IsNullOrEmpty())
                return null;
            return decimal.Parse(value);
        }

        public static double? ToNullableDouble(this string value)
        {
            if (value.IsNullOrEmpty())
                return null;
            return double.Parse(value);
        }

        public static int? ToNullableInt(this string value)
        {
            if (value.IsNullOrEmpty())
                return null;
            return int.Parse(value);
        }

        public static long? ToNullableLong(this string value)
        {
            if (value.IsNullOrEmpty())
                return null;
            return long.Parse(value);
        }

        public static long ToLong(this string value)
        {
            return long.Parse(value);
        }

        public static DateTime ToDateTime(this string value)
        {
            return DateTime.Parse(value);
        }

        public static short ToShort(this string value)
        {
            return short.Parse(value);
        }

        public static decimal ToDecimal(this string value)
        {
            return decimal.Parse(value);
        }

        public static double ToDouble(this string value)
        {
            return double.Parse(value);
        }

        public static int ToInt(this string value)
        {
            return int.Parse(value);
        }

        public static char ToChar(this string value)
        {
            return char.Parse(value);
        }

        public static char ToChar(this string value, char defaultValue)
        {
            char result;
            if (!char.TryParse(value, out result))
                return defaultValue;
            return result;
        }

        public static char ToChar(this int value)
        {
            return char.Parse(value.ToString());
        }

        public static char? ToNullableChar(this string value)
        {
            if (value.IsNullOrEmpty())
                return null;
            return char.Parse(value);
        }

        #region Dictionaries

        public static TValue GetOrAdd<TKey, TValue>(this IDictionary<TKey, TValue> dict, TKey key, Func<TKey, TValue> creator)
        {
            TValue result;
            if (!dict.TryGetValue(key, out result))
            {
                result = creator(key);
                dict.Add(key, result);
            }
            return result;
        }

        public static TValue GetOrAdd<TKey, TValue>(this IDictionary<TKey, TValue> dict, TKey key, Func<TValue> creator)
        {
            TValue result;
            if (!dict.TryGetValue(key, out result))
            {
                result = creator();
                dict.Add(key, result);
            }
            return result;
        }

        public static TValue GetOrAdd<TKey, TValue>(this IDictionary<TKey, TValue> dict, TKey key) where TValue : new()
        {
            TValue result;
            if (!dict.TryGetValue(key, out result))
            {
                result = new TValue();
                dict.Add(key, result);
            }
            return result;
        }

        public static void SetOrAdd<TKey, TValue>(this IDictionary<TKey, TValue> dict, TKey key, TValue value)
        {
            if (dict.ContainsKey(key))
                dict[key] = value;
            else
                dict.Add(key, value);
        }

        public static TValue GetOrDefault<TKey, TValue>(this IDictionary<TKey, TValue> dict, TKey key)
        {
            TValue result;
            dict.TryGetValue(key, out result);
            return result;
        }

        public static TValue GetOrDefault<TKey, TValue>(this IDictionary<TKey, TValue> dict, TKey key, TValue defaultValue)
        {
            TValue result;
            if (!dict.TryGetValue(key, out result))
                return defaultValue;
            return result;
        }

        #endregion

        /// <summary>
        /// Realiza full join em ambas os dictionários. Configura valor default quando não há correlação.
        /// </summary>
        /// <typeparam name="TKey">Tipo de chave para comparação</typeparam>
        /// <typeparam name="TValue">Tipo de elemento da lista</typeparam>
        /// <param name="list1">Dicionário 1</param>
        /// <param name="list2">Dicionário 2</param>
        /// <returns>Enumerador com os pares e chaves encontrados</returns>
        public static IEnumerable<DictionaryFullJoinResult<TKey, TValue>> FullJoin<TKey, TValue>(this IEnumerable<KeyValuePair<TKey, TValue>> list1, IEnumerable<KeyValuePair<TKey, TValue>> list2)
        {
            return FullJoin(list1, list2, i => i.Key, i => i.Key, (k, i, j) => { return new DictionaryFullJoinResult<TKey, TValue>(k, i.Value, j.Value); }, EqualityComparer<TKey>.Default);
        }


        /// <summary>
        /// Realiza full join em ambas as listas. Configura valor default quando não há correlação. Não é permitido ter duplicidade das chaves nas listas.
        /// </summary>
        /// <typeparam name="TKey">Tipo de chave para comparação</typeparam>
        /// <typeparam name="TValue">Tipo de elemento da lista</typeparam>
        /// <param name="list1">Lista 1</param>
        /// <param name="list2">Lista 2</param>
        /// <param name="keySelector">Selecionador da chave</param>
        /// <returns>Enumerador com os pares encontrados</returns>
        public static IEnumerable<FullJoinResult<TKey, TValue, TValue>> FullJoin<TKey, TValue>(this IEnumerable<TValue> list1, IEnumerable<TValue> list2, Func<TValue, TKey> keySelector)
        {
            return FullJoin(list1, list2, keySelector, keySelector, (k, i, j) => { return new FullJoinResult<TKey, TValue, TValue>(k, i, j); }, EqualityComparer<TKey>.Default);
        }

        /// <summary>
        /// Realiza full join em ambas as listas. Configura valor default quando não há correlação. Não é permitido ter duplicidade das chaves nas listas.
        /// </summary>
        /// <typeparam name="TKey">Tipo de chave para comparação</typeparam>
        /// <typeparam name="TValueLeft">Tipo de elemento da lista 1</typeparam>
        /// <typeparam name="TValueRight">Tipo de elemento da lista 2</typeparam>
        /// <typeparam name="TResult">Tipo do resultado</typeparam>
        /// <param name="listLeft">Lista 1</param>
        /// <param name="listRight">Lista 2</param>
        /// <param name="keySelectorLeft">Selecionador de chave da lista 1</param>
        /// <param name="keySelectorRight">Selecionador de chave da lista 2</param>
        /// <param name="resulter">Criador do resultado</param>
        /// <returns>Enumerador com os pares encontrados e transformado por resulter</returns>
        public static IEnumerable<TResult> FullJoin<TKey, TValueLeft, TValueRight, TResult>(this IEnumerable<TValueLeft> listLeft, IEnumerable<TValueRight> listRight, Func<TValueLeft, TKey> keySelectorLeft, Func<TValueRight, TKey> keySelectorRight, Func<TKey, TValueLeft, TValueRight, TResult> resulter)
        {
            return FullJoin(listLeft, listRight, keySelectorLeft, keySelectorRight, resulter, EqualityComparer<TKey>.Default);
        }

        /// <summary>
        /// Realiza full join em ambas as listas. Configura valor default quando não há correlação. Não é permitido ter duplicidade das chaves nas listas.
        /// </summary>
        /// <typeparam name="TKey">Tipo de chave para comparação</typeparam>
        /// <typeparam name="TValueLeft">Tipo de elemento da lista 1</typeparam>
        /// <typeparam name="TValueRight">Tipo de elemento da lista 2</typeparam>
        /// <typeparam name="TResult">Tipo do resultado</typeparam>
        /// <param name="listLeft">Lista 1</param>
        /// <param name="listRight">Lista 2</param>
        /// <param name="keySelectorLeft">Selecionador de chave da lista 1</param>
        /// <param name="keySelectorRight">Selecionador de chave da lista 2</param>
        /// <param name="comparer">Comparador das chaves</param>
        /// <param name="resulter">Criador do resultado</param>
        /// <returns>Enumerador com os pares encotrados e transformado por resulter</returns>
        public static IEnumerable<TResult> FullJoin<TKey, TValueLeft, TValueRight, TResult>(this IEnumerable<TValueLeft> listLeft, IEnumerable<TValueRight> listRight, Func<TValueLeft, TKey> keySelectorLeft, Func<TValueRight, TKey> keySelectorRight, Func<TKey, TValueLeft, TValueRight, TResult> resulter, IEqualityComparer<TKey> comparer)
        {
            var l1 = listLeft.Select(i =>
            {
                var key = keySelectorLeft(i);
                return new { hash = comparer.GetHashCode(key), key, value = i };
            }).OrderBy(i => i.hash).ToArray();

            var l2 = listRight.Select(i =>
            {
                var key = keySelectorRight(i);
                return new { hash = comparer.GetHashCode(key), key, value = i };
            }).OrderBy(i => i.hash).ToArray();

            var i1 = 0;
            var i2 = 0;

            var c1 = l1.Length;
            var c2 = l2.Length;

            if (c1 == 0) goto endfor1;
            if (c2 == 0) goto endfor2;

            var hash1 = l1[0].hash;
            var hash2 = l2[0].hash;

            while (true)
            {
                while (hash1 < hash2)
                {
                    yield return resulter(l1[i1].key, l1[i1].value, default(TValueRight));
                    if (++i1 >= c1) goto endfor1;
                    hash1 = l1[i1].hash;
                }

                while (hash2 < hash1)
                {
                    yield return resulter(l2[i2].key, default(TValueLeft), l2[i2].value);
                    if (++i2 >= c2) goto endfor2;
                    hash2 = l2[i2].hash;
                }

                if (hash1 == hash2)
                {
                    var b1 = i1; // begin range
                    var b2 = i2;
                    // i1 e i2 se tornam o end range
                    while (++i1 < c1 && l1[i1].hash == hash1) ;
                    while (++i2 < c2 && l2[i2].hash == hash2) ;

                    // Para cada l1 verificar set bate com l2 e retornar, se num bater ninguém retorna um com null em l2
                    for (int i = b1; i < i1; i++)
                    {
                        bool hasMacth = false;
                        for (int j = b2; j < i2; j++)
                            if (comparer.Equals(l1[i].key, l2[j].key))
                            {
                                hasMacth = true;
                                yield return resulter(l1[i].key, l1[i].value, l2[j].value);
                            }

                        if (!hasMacth)
                            yield return resulter(l1[i].key, l1[i].value, default(TValueRight));
                    }

                    // verifica os l2 que num tem em l1
                    for (int j = b2; j < i2; j++)
                    {
                        for (int i = b1; i < i1; i++)
                            if (comparer.Equals(l1[i].key, l2[j].key))
                                goto ok;
                        yield return resulter(l2[j].key, default(TValueLeft), l2[j].value);
                    ok: ;
                    }

                    // verifica o status dos end ranges...
                    if (i1 >= c1) goto endfor1;
                    if (i2 >= c2) goto endfor2;
                }
            }

        endfor1:
            while (i2 < c2)
            {
                yield return resulter(l2[i2].key, default(TValueLeft), l2[i2].value);
                i2++;
            }
            goto end;
        endfor2:
            while (i1 < c1)
            {
                yield return resulter(l1[i1].key, l1[i1].value, default(TValueRight));
                i1++;
            }
        end: ;
        }

    }

    public class DictionaryFullJoinResult<TKey, TValue>
    {
        public DictionaryFullJoinResult(TKey key, TValue left, TValue right)
        {
            this.Key = key;
            this.Left = left;
            this.Right = right;
        }

        public TKey Key { get; private set; }
        public TValue Left { get; private set; }
        public TValue Right { get; private set; }
    }

    public class FullJoinResult<TKey, TValueLeft, TValueRight>
    {
        public FullJoinResult(TKey key, TValueLeft left, TValueRight right)
        {
            this.Key = key;
            this.Left = left;
            this.Right = right;
        }

        public TKey Key { get; private set; }
        public TValueLeft Left { get; private set; }
        public TValueRight Right { get; private set; }
    }
    #endregion
}
