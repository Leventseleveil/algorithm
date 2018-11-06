package HuarongRoad;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.SplashScreen;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;

import com.sun.corba.se.spi.orbutil.fsm.Action;

import HuarongRoad.Person;

public class HuarongRoad extends JFrame implements MouseListener,KeyListener,ActionListener{
	 @Override//�� �� �� ��
	 public void setTitle(String title) {
		 super.setTitle(title);
	 }
	 private JPanel contentPane, panel;
	 Person person[] = new Person[10];  //found persons
	 JButton left, right , above , below,belowx;    
	 JButton restart,undo;//�� �� �� ʼ�� �� ��
	 JLabel label,label2;
	 JTextArea count;//����
	 static int number = 0;
	 
	 static int X[] = new int[500]; //�� ¼ ÿ һ �� ��
	 static int Y[] = new int[500]; 
	 Person p[] = new Person[500];
	 
	 public HuarongRoad() {  	// �� ʼ ��
		 contentPane = new JPanel();
		 contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));		
		 contentPane.setLayout(null);
		 setContentPane(contentPane);
			
		 panel = new JPanel();
		 panel.setBackground(new Color(218, 165, 32));
		 panel.setBounds(10, 10, 420, 520);
		 panel.setLayout(null);
		 contentPane.add(panel);
	     init();  
	     setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);   
	     setBounds(25, 25, 500, 650);  
	     setVisible(true);  
	   }
	
	public void init() {          //�� ʼ ��
		label = new JLabel("��     ��");
		label2 = new JLabel("������");
		count = new JTextArea();
		count.setEditable(false);
		contentPane.add(label);
		contentPane.add(label2);
		contentPane.add(count);
		
		label.setFont(new Font("����",Font.BOLD,30)); 
		label.setBounds(150, 535, 150, 35);
		label2.setFont(new Font("����",Font.BOLD,30)); 
		label2.setBounds(310, 535, 100, 35);
		count.setFont(new Font("����",Font.BOLD,35)); 
		count.setBounds(390, 535, 60, 35);
		count.setText(number + "");
		
		undo = new JButton("����");
		restart = new JButton("���¿�ʼ");
		belowx = new JButton("");
		contentPane.add(undo);
		contentPane.add(restart);//init restart
		
		undo.setBounds(10, 570, 80, 40);  
	    undo.addActionListener(new unDo());
		restart.setBounds(95, 570, 100, 40);  
	    restart.addActionListener(this);
	    
	    
	    left = new JButton();//init  wall   
	    right = new JButton();  
	    above = new JButton();   
	    below = new JButton();
	    belowx = new JButton();
	    panel.add(left);   
	    panel.add(right);  
	    panel.add(above);   
	    panel.add(belowx);
	    panel.add(below);
	    
	    
	    left.setBounds(0, 0, 10, 520);  
	    right.setBounds(410, 0, 10, 520);  
	    above.setBounds(10, 0, 400, 10);  
	    below.setBounds(10, 510, 400, 10);
	    belowx.setBounds(110, 510, 200, 10);
	    belowx.setBackground(new Color(218, 165, 32)); 
	    
	    
	    String name[] = {"", "", "", "", "", "", "", "", "", ""};//init persons
	    for(int k = 0;k < name.length; k++) {  
	    	person[k] = new Person(k,name[k]);  
	        person[k].addMouseListener(this);  
	        person[k].addKeyListener(this);  
	        panel.add(person[k]);
	    }
	    person[0].setBounds(110, 10, 200, 200); 
	    person[0].setForeground(Color.PINK);
	    setIcon("src/HuarongRoad/�ܲ�.png",person[0]);
	    person[1].setBounds(110, 210, 200, 100);
	    setIcon("src/HuarongRoad/����.png",person[1]);
	    person[2].setBounds(10, 210, 100, 200); 
	    setIcon("src/HuarongRoad/��.png",person[2]);
	    person[3].setBounds(310, 210, 100, 200); 
	    setIcon("src/HuarongRoad/�ŷ�.png",person[3]);
	    person[4].setBounds(10, 10, 100, 200);  
	    setIcon("src/HuarongRoad/����.png",person[4]);
	    person[5].setBounds(310, 10, 100, 200);  
	    setIcon("src/HuarongRoad/����.png",person[5]);
	    person[6].setBounds(110, 310, 100, 100); 
	    setIcon("src/HuarongRoad/��.png",person[6]);
	    person[7].setBounds(210, 310, 100, 100);  
	    setIcon("src/HuarongRoad/��.png",person[7]);
	    person[8].setBounds(10,410,100,100);  
	    setIcon("src/HuarongRoad/��.png",person[8]);
	    person[9].setBounds(310,410,100,100); 
	    setIcon("src/HuarongRoad/��.png",person[9]);
	    person[9].requestFocus();    	
	}
	
	@Override  
	public void keyPressed(KeyEvent e) {  //���µĴ����ж��ܷ�����ƶ�
	Person man = (Person) e.getSource(); //��ȡ�¼������õĶ������ã�����ѡ����Ǹ�button�� 
	     if(e.getKeyCode() == KeyEvent.VK_DOWN)  
	         move(man, below);  
	     if(e.getKeyCode() == KeyEvent.VK_UP)  
	         move(man, above);  
	     if(e.getKeyCode() == KeyEvent.VK_LEFT)  
	         move(man, left);  
	     if(e.getKeyCode() == KeyEvent.VK_RIGHT)  
	        move(man, right);  
	   }
	
	public boolean move(Person personX, JButton wall) {
		boolean isMove = true;
		Rectangle personXRect = personX.getBounds();
		int x = personX.getX();
		int x1 = x;
		int y = personX.getY();
		int y1 = y;
		
		if(wall == below) y += 100;
		else if(wall == above) y -= 100;
		else if(wall == right) x += 100;
		else if(wall == left) x -= 100;
		personXRect.setLocation(x, y);//��Ҫ�ƶ�����λ��
		
		Rectangle thisIsWall= wall.getBounds();
		if(personXRect.intersects(thisIsWall)) isMove = false;//�� personX �� �� �� �� ǽ �� ��
		
		for (int k = 0; k < this.person.length; k++) {//�� personX �� �� �� �� �� �� ��
			Rectangle personRect = person[k].getBounds();
			if ((personXRect.intersects(personRect))&&(personX.number != k)) isMove = false;
		}
		
		if(isMove == true) {//�� �� �� �� �� �� �� ���� �� ¼ �� ���� �� �� + 1��
			personX.setLocation(x, y);
			p[number] = personX;
			X[number] = x1;
			Y[number] = y1;
	
		    number++;
			count.setText(number + "");			
		}
		
		return isMove;
	}
	
	public boolean getRandom() {
		boolean m = true;
		double random = Math.random();
		if(random >= 0.5) return m; 
		else {
			m = false;
			return m;
		}
	}

	@Override
	public void actionPerformed(ActionEvent e) {//restart
		dispose();
		number = 0;
		p = null;
		new HuarongRoad().setTitle("���仪�ݵ�");	
	}
	
	class unDo implements ActionListener {	
		@Override
		public void actionPerformed(ActionEvent e) {
		
			if(number > 0) {
				int x1 = X[number-1];
				int y1 = Y[number-1];			
				p[number-1].setLocation(x1, y1);
				
				number--;
				count.setText(number + "");
			}
		}
		
	}
	
	class Count implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			number++;
		}
	} 
	
	public void setIcon(String file, JButton iconButton) {//ͼ Ƭ �� Ӧ �� �� ��  
        ImageIcon icon = new ImageIcon(file);  
        Image temp = icon.getImage().getScaledInstance(iconButton.getWidth(),  
                iconButton.getHeight(), icon.getImage().SCALE_DEFAULT);  
        icon = new ImageIcon(temp);  
        iconButton.setIcon(icon);  
    }  
	
	public void keyTyped(KeyEvent e){}  
	public void keyReleased(KeyEvent e){}
	public void mouseClicked(MouseEvent e) {}
	public void mousePressed(MouseEvent e) {}
	public void mouseReleased(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
	
	public static void main(String[] args) {
		new HuarongRoad().setTitle("���仪�ݵ�");
	}
}

