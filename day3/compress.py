import os
def compress_file_rle(input_file_path, output_file_path):
    if not os.path.exists(input_file_path):
        print(f"Error: The file '{input_file_path}' does not exist.")
        return
    with open(input_file_path, "r", encoding="utf-8") as infile, open(
        output_file_path, "w", encoding="utf-8"
    ) as outfile:
        current_char = infile.read(1)
        if not current_char:
            print("The input file is empty.")
            return 
        count = 1
        while True:
            next_char = infile.read(1)
            if not next_char:
                outfile.write(f"{current_char}{count}")
                break

            if next_char == current_char:
                count += 1
            else:
                outfile.write(f"{current_char}{count}")
                current_char = next_char
                count = 1
    orig_size = os.path.getsize(input_file_path)
    comp_size = os.path.getsize(output_file_path)
    print("--- Compression Completed Successfully ---")
    print(f"Original File Size   : {orig_size} bytes")
    print(f"Compressed File Size : {comp_size} bytes")
input_filename = "sample.txt"
output_filename = "compressed.rle"
compress_file_rle(input_filename, output_filename)
