/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Extending;

/**
 *
 * @author Zobayer
 */
public class ExtendedThread {
    public static void main(String [] args) {
        NewThread nt = new NewThread();
        
        nt.start();
        
        try {
            for (int i = 5; i > 0; --i) {
                System.out.println("Main Thread: " + i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }
         System.out.println("Main thread exiting.");
    }
}













