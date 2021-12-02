# directions = ["forward 5", "down 5", "forward 8", "up 3", "down 8" , "forward 2"]

with open("directions.txt") as input_file:
    directions = list(input_file.readlines())


horizontal_position, depth = 0, 0
for direction, distance in map(str.split, directions):
    distance = int(distance)
    if direction == "forward":
        horizontal_position += distance
    if direction == "back":
        horizontal_position -= distance
    if direction == "down":
        depth += distance
    if direction == "up":
        depth -= distance

print(f"{horizontal_position = }, {depth = }")
print(f"solution = {horizontal_position * depth}")
        
