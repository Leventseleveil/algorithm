package HuarongRoad;
import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;


public class Person extends JButton implements FocusListener {   
	   int number;      
	   Person(){
		   this(666,"2333");
	   }
	   Person(int number,String s) {  
	       super(s);  
	       this.number=number;    
	       addFocusListener(this);  
	   }  	   
	   @Override
	   public void focusGained(FocusEvent e) {
	      setBackground(Color.red);  
	   }    
	   @Override
	   public void focusLost(FocusEvent e) {
	      setBackground(new Color(205, 133, 63));  
	   }  
	   
	}  
