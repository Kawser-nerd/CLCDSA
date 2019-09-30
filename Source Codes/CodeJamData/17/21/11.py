#!/usr/bin/python3
# Copyright (C) 2017 Sayutin Dmitry.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; version 3
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; If not, see <http://www.gnu.org/licenses/>.

def main():
    T = int(input())
    for t in range(T):
        D, N = map(int, input().split())

        time = -1
        for i in range(N):
            K, S = map(int, input().split())
            time = max(time, (D - K) / S)

        print("Case #{}: {}".format(t + 1, "{0:.9f}".format(D / time)))

main()
