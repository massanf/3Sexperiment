close all; clear; clc; s = tf('s');
C = 4.7 * 10^(-10);
L = 47*10^(-6); % [microH]
wn = 1/sqrt(L*C); % calc wn
zeta = 1;

R = 2*zeta*sqrt(L/C); % calc theoretical R to select feasible R
zeta1 = R/2*sqrt(C/L);

%C = 1/(4*pi^2*(10^12)*L);
%R4 = 6.8*10^2; zeta4 = R4/2*sqrt(C/L); fprintf('zeta4=%f\n',zeta4);

% transfer functions
G = (wn^2)/(s^2+2*zeta1*wn*s+wn^2);

figure; bode(G);
grid on;    % show grid
legend;     % show legend
saveas(gcf, 'rlc_bode_ideal.png');   % save as png file

figure; pzmap(G);
daspect([1 1 1]);               % aspect ratio
legend('Location','northwest'); % show legend
saveas(gcf, 'rlc_pzmap_ideal.png');  % save as png file

figure; step(G);
grid on;    % show grid
legend;     % show legend
xlim([0 1e-5]);
ylim([-0.8*10^6 0.8*10^6]);
saveas(gcf, 'rlc_step_ideal.png');   % save as png file
