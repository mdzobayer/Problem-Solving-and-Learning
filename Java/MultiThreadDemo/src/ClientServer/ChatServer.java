/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ClientServer;

/**
 *
 * @author Zobayer
 */
import java.net.*;
import java.io.*;

public class ChatServer {
    public static void main(String [] args) throws Exception {
//        ServerSocket server = new ServerSocket(10007);
//        Socket sock = server.accept();
//        BufferedReader input = new BufferedReader (
//            new InputStreamReader(sock.getInputStream()));
//        PrintStream output = new PrintStream(sock.getOutputStream());
//        BufferedReader serverInput = new BufferedReader(
//            new InputStreamReader(System.in));
//        String line;
//        while(true) {
//            line = input.readLine();
//            if (line.equals("bye")) {
//                break;
//            }
//            System.out.println("Client: " + line);
//            System.out.print("Server: ");
//            line = serverInput.readLine();
//            output.println(line);
//        }
//        server.close();
//        sock.close();
//        input.close();
//        output.close();
//        serverInput.close();
        //
        System.out.println("Before 2nd thread");
        SendMsgThread sm = new SendMsgThread("server");
        ReceiveMsgThread rm = new ReceiveMsgThread("server");
        
        rm.t.join();
        sm.t.join();
        
    }
}
