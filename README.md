# Fractol

Fractol is a project aimed to teach 42 students how to work with a graphics library. The assignement was to create the Mandelbrotset and the Juliaset using the graphics library. `minilibx`.
<p> &nbsp </p>

## Fractals
A fractal is created based on complex numbers. It follows a formula where you replace some part of the equation with the result of the previous calculation, the
repeated replacing and recalculation is called an iteration. You can zoom into fractals nearly infinitely (only limited by the precision of doubles) and while zooming in you will find patterns which look similar
to the start pattern (self similarity).
<p> &nbsp </p>

## Mandelbrot
Mandelbrot is a fractal which is created by calculating the formula z<sub>n + 1</sub> = z<sub>n</sub><sup>2</sup> + c, where z<sub>0</sub> = 0. The value `c` is the fixed value of the pixel in the coordinate system. Depending on the max iteration and the color scheme you can see a variation of details.
![alt text](https://github.com/HoergerL/fractol/blob/master/Pictures/Mandelbrot_start.png)
<p> &nbsp </p>

## Julia
The Julia set is based on the same formula as the Mandelbrot set, but while calculating the Julia Set `z` starts at a fixed complex number (in this implementation this is taken from Input (`argv`)) and `c`, starting at 0, is replaced by the result of the previous calculation. 
![alt text](https://github.com/HoergerL/fractol/blob/master/Pictures/Julia.png)
<p> &nbsp </p>

## functionality
1. zoom follows the mouseposition 
<img src="https://github.com/HoergerL/fractol/blob/master/Pictures/Mandelbrot_zoom_in.png" height="200">
<img src="https://github.com/HoergerL/fractol/blob/master/Pictures/Julia_zoom_in.png" height="200">
2. moving with the arrow keys
<img src="https://github.com/HoergerL/fractol/blob/master/Pictures/Mandelbrot_moved.png" height="200">
3. changing colors with the Button c
<img src="https://github.com/HoergerL/fractol/blob/master/Pictures/Mandelbrot_different_color.png" height="200">
<img src="https://github.com/HoergerL/fractol/blob/master/Pictures/Mandelbrot_different_color2.png" height="200">
4.  increase/decrease quality (max_iteration)
<img src="https://github.com/HoergerL/fractol/blob/master/Pictures/Mandelbrot_less_max_iteration.png" height="200">
<img src="https://github.com/HoergerL/fractol/blob/master/Pictures/Mandelbrot_high_max_iteration.png" height="200">
5. changing the displayed fractal with the numbers 1 (Julia) 2 (Mandelbrot) and 3 (Tricorn)
<img src="https://github.com/HoergerL/fractol/blob/master/Pictures/tricorn.png" height="200">
<p> &nbsp </p>

## how to approach the project (for 42 students)
1. To start with this project, I would recommend to learn about complex numbers first. It is important to understand that you can represent them with a 2D coordinate system. 
2. Then take the formula for Mandelbrot, try to understand how it works and how you have to change it so that you can implement it. With this formula you have to calculate the color of every single pixel. The following video helped me a lot, but sadly it's int German: https://www.youtube.com/watch?v=LaHSbUWAQUE.
3. You can do this step independenly from the first two: Download the minilibx and try to understand how you can draw a single pixel (this guide will help you: <a>https://harm-smits.github.io/42docs/libs/minilibx</a>, the getting started part is the most important section).
4. Once you got the hang of minilibx try to draw Mandelbrot with it. Hint: It is best to start with only 2 colors and expand the range of colors afterwards.

