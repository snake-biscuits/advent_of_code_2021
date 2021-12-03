# diagnostic = ["00100", "11110", "10110", "10111", "10101", "01111",
#               "00111", "11100", "10000", "11001", "00010", "01010"]

with open("diagnostic.txt") as input_file:
    diagnostic = [L.strip("\n") for L in input_file.readlines()]

bits = {i: {0: 0, 1: 0} for i in range(12)}

for binary in diagnostic:
    for i, bit in enumerate(binary):
        bits[11 - i][int(bit)] += 1

gamma_rate = 0
epsilon_rate = 0

for i, b in bits.items():
    case = b[1] > b[0]
    bit_value = 2 ** i
    gamma_rate += bit_value if case else 0
    epsilon_rate += 0 if case else bit_value

print(f"{gamma_rate:05b}, {epsilon_rate:05b}")
print(gamma_rate * epsilon_rate)
