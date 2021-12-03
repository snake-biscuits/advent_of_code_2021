import collections
import copy
from typing import Dict, List


diagnostic = ["00100", "11110", "10110", "10111", "10101", "01111",
              "00111", "11100", "10000", "11001", "00010", "01010"]

# with open("diagnostic.txt") as input_file:
#     diagnostic = [L.strip("\n") for L in input_file.readlines()]


oxy_group = copy.deepcopy(diagnostic)
co2_group = copy.deepcopy(diagnostic)
print(f"{oxy_group = }")
print(f"{co2_group = }")


def calc_bits(diagnostic: List[str]) -> Dict[int, Dict[int, int]]:
    bits = collections.defaultdict(lambda: {0: 0, 1: 1})
    for binary in diagnostic:
        for i, bit in enumerate(binary):
            bits[i][int(bit)] += 1
    return bits


oxy_bits = calc_bits(diagnostic)
co2_bits = copy.deepcopy(oxy_bits)

for i in oxy_bits.keys():
    if oxy_bits[i][0] > oxy_bits[i][1]:
        oxy_group = list(filter(lambda b: b[i] == "0", oxy_group))
    else:
        oxy_group = list(filter(lambda b: b[i] == "1", oxy_group))
    oxy_bits = calc_bits(oxy_group)
    if co2_bits[i][0] > co2_bits[i][1]:
        co2_group = list(filter(lambda b: b[i] == "1", co2_group))
    else:
        co2_group = list(filter(lambda b: b[i] == "0", co2_group))
    co2_bits = calc_bits(co2_group)
    print(i)
    print(f"{oxy_group = }")
    print(f"{oxy_bits = }")
    print(f"{co2_group = }")
    print(f"{co2_bits = }")
    if len(oxy_group) == 1:
        oxy_rating = int(oxy_group[0], 2)
        print(f"{oxy_rating = }")
    if len(co2_group) == 1:
        co2_rating = int(co2_group[0], 2)
        print(f"{co2_rating = }")

print(f"{oxy_rating = }, {co2_rating = }")
print(f"life_support_rating = {oxy_rating * co2_rating}")
