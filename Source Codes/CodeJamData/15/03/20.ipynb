{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 16,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": [
    "transfer = {'1': {'1':'1', 'i':'i', 'j':'j', 'k':'k', '-1':'-1'},\n",
    "           'i': {'1':'i', 'i':'-1', 'j':'k', 'k':'-j', '-1':'-i'},\n",
    "           'j': {'1':'j', 'i':'-k', 'j':'-1', 'k':'i', '-1':'-j'},\n",
    "           'k': {'1':'k', 'i':'j', 'j':'-i', 'k':'-1', '-1':'-k'},\n",
    "           '-1': {'1':'-1', 'i':'-i', 'j':'-j', 'k':'-k', '-1':'1'},}\n",
    "def multiply(a, b):\n",
    "    minuses = 0\n",
    "    if a.startswith('-'):\n",
    "        minuses += 1\n",
    "        a = a[1]\n",
    "    if b.startswith('-'):\n",
    "        minuses += 1\n",
    "        b = b[1]  \n",
    "    res = transfer[a][b]\n",
    "    if minuses % 2 == 0:\n",
    "        return res\n",
    "    else:\n",
    "        if res.startswith('-'):\n",
    "            return res[1:]\n",
    "        else:\n",
    "            return '-' + res"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 12,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": [
    "def read_input(fin_name):\n",
    "    with open(fin_name, 'r') as fin:\n",
    "        nb_cases = int(fin.readline())\n",
    "        for _ in xrange(nb_cases):\n",
    "            l, x = map(int, fin.readline().split())\n",
    "            spell = list(fin.readline().strip())\n",
    "            yield (l, x, spell)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 13,
   "metadata": {
    "collapsed": false
   },
   "outputs": [],
   "source": [
    "def proceed(case):\n",
    "    l, x, spell = case\n",
    "    small_x = min(x, 4)\n",
    "    acc = '1'\n",
    "    cum = []\n",
    "    for i in xrange(small_x):\n",
    "        for letter in spell:\n",
    "            acc = multiply(acc, letter)\n",
    "            cum.append(acc)\n",
    "    if ('i' not in cum) or ('k' not in cum):\n",
    "        return False\n",
    "    if (x <= 4):\n",
    "        if 'k' not in cum[cum.index('i'):]:\n",
    "            return False\n",
    "    if (x < 2*4):\n",
    "            if 'k' not in (cum*2)[:(l*x)][cum.index('i'):]:\n",
    "                return False\n",
    "    x_mod_4 = x % 4\n",
    "    if cum[(x_mod_4 * l)-1] != '-1':\n",
    "        return False\n",
    "    return True"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 14,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": [
    "def runit(fin_name, fout_name):\n",
    "    with open(fout_name, 'w') as fout:\n",
    "        for i, case in enumerate(read_input(fin_name), 1):\n",
    "            fout.write('Case #{}: {}\\n'.format(i, 'YES' if proceed(case) else 'NO'))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 19,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": [
    "runit('C-small-attempt0.in', 'C-small-attempt0.out')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 20,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": [
    "runit('C-large.in', 'C-large.out')"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 2",
   "language": "python",
   "name": "python2"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 2
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython2",
   "version": "2.7.9"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 0
}
