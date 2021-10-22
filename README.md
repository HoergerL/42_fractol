# Fractol

Fractol is a project aimed to teach 42 students how to work with a graphic library. The graphic library `minilibx` is given by 42 and the usage is mandatory.
With `minilibx` you have to create the fractals Mandelbrot and Julia.

## Fractals
A fractal is created based on complex numbers. It follows a formula where you replace some part of the formula with the result of the previous calculation, the
repeated replacing and recalculation is called iteration. You can zoom into fractals nearly infinitely and while zooming in you will find patterns which look similar
to the start pattern (self similarity).

## Mandelbrot
Mandelbrot is a fractol which is created by calculating the formula z<sub>n + 1</sub> = z<sub>n</sub><sup>2</sup> + c, where z<sub>0</sub> = 0. The value `c` is the fixed value of the pixel in the coordinate system. Depending on the max iteration and the color scheme you can see a variation of details.
![alt text](https://github.com/HoergerL/fractol/blob/master/Pictures/Mandelbrot_start.png)
<p> &nbsp </p>

## Julia
The Julia set is based on the same formula as the Mandelbrot set, but while calculating the Julia Set `z` starts at a fixed complex number (in this implementation this is taken from Input (`argv`)) and `c`, starting at 0, is replaced by the result of the previous calculation. 
![alt text](https://github.com/HoergerL/fractol/blob/master/Pictures/Julia.png)
<p> &nbsp </p>

## approach to the project (for 42 students)
1. To start with this project, I would recommend to learn about complex numbers first. Important is to understand that you can represent them with a 2 dimensional coordinate system. 
2. Then take the formula for Mandelbrot, try to understand how it works and how you have to change it so that you can implement it. 
3. You can do this step totally seperated from the first two: Download the minilibx and try to understand how you can draw single pixel (this guide will help you: <a>https://harm-smits.github.io/42docs/libs/minilibx</a>)
