# Fractol  
**Exploring the Beauty of Fractals**  

Fractol is a graphical program designed to visualize and explore the mesmerizing world of fractals. This project combines the elegance of mathematical complexity with the power of OpenGL and C programming to create stunning visual representations.

## Features  

### Fractal Rendering  
- **Mandelbrot Set**: Dive into the infinite complexity of the Mandelbrot fractal.  
- **Julia Set**: Generate and explore various Julia sets by passing custom parameters.  

### Dynamic Interactions  
- **Zooming**: Use the mouse wheel to zoom infinitely (within computational limits).  
- **Smooth Graphics**: Handles window events like minimization and switching without disruption.  
- **Customizable Parameters**: Define fractal types and other options via command-line arguments.  

### Stunning Visuals  
- **Color Depth**: Each fractal showcases unique depth through vivid color schemes.  
- **Psychedelic Effects**: Unlock visual brilliance with customizable and dynamic color effects.  

### Seamless Controls  
- **ESC Key**: Cleanly exits the program.  
- **Window Close Button**: Properly shuts down the program when the window is closed.  

## Installation  

### Requirements  
- A UNIX-like operating system.  
- GCC or Clang compiler.  
- GNU Make.  
- OpenGL and X11 libraries.  

### Build Steps  
Clone the repository:  
```bash  
git clone https://github.com/yourusername/fractol.git  
cd fractol  
```  

Build the project:  
```bash  
make  
```  

Run the program:  
```bash  
./fractol <fractal_type> [options]  
```  

Clean the build files:  
```bash  
make clean  
```  

## Usage  

### Available Fractals  
- `mandelbrot`: Visualize the Mandelbrot set.  
- `julia [params]`: Generate a custom Julia set by providing parameters.  

### Example Commands  
```bash  
./fractol mandelbrot  
./fractol julia -0.7 0.27015  
```  

Explore infinite details by zooming and interacting directly with the rendered fractals!  

## Contributing  

Contributions are welcome!  
- Fork the repository.  
- Create a new branch: `git checkout -b feature-name`.  
- Commit your changes: `git commit -m 'Add feature'`.  
- Push to the branch: `git push origin feature-name`.  
- Open a Pull Request.  

Make sure to adhere to the projectâ€™s coding standards and document your additions.  

## License  

This project is licensed under the [MIT License](LICENSE).  

## Acknowledgments  

Inspired by the elegance of fractals and their infinite complexity, Fractol brings art and mathematics together in a stunning graphical display.  
