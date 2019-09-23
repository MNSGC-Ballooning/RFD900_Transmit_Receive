function test()
% Reads in data from RFD900 radios or other packet radios and displays
% messages in command window.

% Author: Andrew Van Gerpen

close all; clear; clc; format compact;
cleanupObj = onCleanup(@cleanup);
seriallist                              % this will probably not work first try because
                                        % you will have to change the COM port that your RFD is on below.
           %      \/   It will output first time you run the program
port = serial("COM19", "BaudRate",38400); %COM# will need to be changed inside the function here
fopen(port);
while 1                                 % Stays in the loop until ctrl + c is hit
    if port.bytesAvailable              % only runs the code below if bytes come in through the radio
        pause(0.1);                     % janky way to let the port fill with all bytes from the message
        bytes = port.BytesAvailable;    % Save this bytenumber valuable as a variable
        x = fread(port,bytes);          % reads the full number of bytes and saves it as one variable array
        x = char(x);                    % changes the bytes from ascii to characters (i think)
        disp(x)                         % displays the message
    end
end

%% Cleanup function.
    function cleanup()      % Matlab automatically runs this when you hit ctrl-c to end the program
        %disp("hi")         % Making sure the cleanup function is running
        fclose(port);       
        delete(port);
        clear port
        fclose('all');
    end
end
