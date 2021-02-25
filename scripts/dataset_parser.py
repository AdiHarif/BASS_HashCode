


def parse_file(file_name):

    OUT_DIR = 'out/dataset_parser'
    IN_DIR = 'datasets'

    path = f'{IN_DIR}/{file_name}.txt'

    in_file = open(path, 'r')
    streets_out = open(OUT_DIR + f'/{file_name}/streets_out.txt', 'w')
    cars_out = open(OUT_DIR + f'/{file_name}/cars_out.txt', 'w')
    line = in_file.readline()
    sim_duration, inter_count, streets_count, cars_count, points_per_car = [int(num) for num in line.split()]

    street_id = 0 
    streets_hash = {}
    while street_id < streets_count:
        line = in_file.readline()
        start_inter, end_inter, name, weight = line.split()
        streets_hash[name] = street_id
        streets_out.write(f'{start_inter} {end_inter} {weight} {street_id}\n')
        street_id += 1
    streets_out.close()

    car_id = 0
    while car_id < cars_count:
        line = in_file.readline().split()
        new_line_list = [line[0]]
        new_line_list.extend([str(streets_hash[name]) for name in line[1:]])
        cars_out.write(f'{" ".join(new_line_list)}\n')
        car_id += 1

    cars_out.close()
    in_file.close()

files = ['a', 'b', 'c', 'd' ,'e', 'f']
for name in files:
    parse_file(name)