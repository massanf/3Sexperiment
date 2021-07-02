close all; clear; clc;
s = tf('s');

f0 = 1*10^(6);
Q = 10;

w = 2*pi*f0;

L = 47*10^(-6); R = 3.3*10;  C = 4.7*(10^-10);

disp(C);

G = (1/(L*C))/(s^2 + (R/L)*s + (1/(L*C)));

%check zeta and wn
wn = sqrt(1/(L*C));
zeta = 1/(2*Q);

figure; step(G); grid;
saveas(gcf,'rlc_step.png');

figure; bode(G); grid on;
saveas(gcf, 'rlc_bode.png');

figure; pzmap(G);
xlim([-wn,wn]);ylim([-wn,wn]);
daspect([1 1 1]);
saveas(gcf, 'rlc_pzmap.png');