% File:   cylindrical_silo.m
% Author: Daric Niclas
% Date:   9/18/19
% Purpose: To determine the cylindrical height h_cyl for given values of r_cyl,
% r_cap, and the total volume of the silo, V_silo.
%
% Formulas:
%   V_cap = (1/3) * PI * (h^2) * (3R-h)
%   h_cap = r_cap * (1-cos(theta)) 
%   h_cyl = (V_cyl - V_cap)/(PI * r^2)

r_cap = input("Cap radius: ");
r_cyl = input("Cylinder radius: ");
V_cyl = input("Cylinder volume: ");

theta = asin(r_cyl/r_cap);
h_cap = r_cap*(1 - cos(theta));
V_cap = (1/3)*pi*(h_cap^2)*(3*r_cap - h_cap);
h_cyl = (V_cyl - V_cap)/(pi*r_cyl^2);

disp("Height of cylinder: " + h_cyl + " feet");