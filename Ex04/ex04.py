#!/usr/bin/env python3
import sys


def read_all() -> list[list[str]]:
    lines: list[str] = []
    all_lines: list[list[str]] = []
    for line in sys.stdin:
        lines = line.rstrip("\n").split(" ")
        if len(lines) != 5:
            continue
        age = int(lines[1])
        masse = int(lines[2])
        if age > 5 or age < 2 or masse > 1500 or masse < 1250:
            continue
        note1 = int(lines[3])
        note2 = int(lines[4])
        if note1 < 0 or note2 < 0 or note1 > 20 or note2 > 20:
            continue
        all_lines.append(lines)
    return all_lines


def sort_cow(all_lines: list[list[str]]) -> list[str]:
    score: int = 0
    for i in all_lines:
        new = int(i[3]) + int(i[4])
        if new > score:
            best = []
            best.append(i[0])
            score = new
        elif new == score:
            best.append(i[0])
    return best


def print_best(best: list[str]) -> int:
    print(best[0], end="")
    for i in best[1::]:
        print(f" {i}", end="")
    print()
    return 0


def main() -> int:
    lines: list[list[str]] = read_all()
    best: list[str] = sort_cow(lines)
    print_best(best)
    return 0


main()
