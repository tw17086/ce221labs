package Assignment;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CE203_2018_Ex1 {
    public static void main(String[] args) {
        new AssFrame("Assignment 1");
    }
}

class AssFrame extends JFrame {
    private int red;
    private int green;
    private int blue;
    //store the values taken from text fields - each referring to a int value corresponding to each of 'RGB'

    AssFrame(String title) {
        //configure the frame
        this.setTitle(title);
        this.setLayout(new BorderLayout());
        this.setSize(500, 400);
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        //make the panels
        JPanel panCentre = new JPanel();
        panCentre.setLayout(new BorderLayout());
        JPanel panBottom = new JPanel();
        JPanel panTop = new JPanel();
        this.add(panCentre, BorderLayout.CENTER);
        this.add(panBottom, BorderLayout.SOUTH);
        this.add(panTop, BorderLayout.NORTH);

        //set the message to display correctly
        JLabel lblMessage = new JLabel("CE203 Assignment 1, submitted by: 1704969");
        lblMessage.setForeground(Color.blue);
        lblMessage.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        lblMessage.setHorizontalAlignment(SwingConstants.CENTER);
        panCentre.add(lblMessage, BorderLayout.CENTER);

        //configure the text fields
        JTextField txtfRed = new JTextField(10);
        JTextField txtfGreen = new JTextField(10);
        JTextField txtfBlue = new JTextField(10);
        panBottom.add(txtfRed);
        panBottom.add(txtfGreen);
        panBottom.add(txtfBlue);

        //create the button that changes colour -- create an action listener for it
        JButton butSetColour = new JButton("Set colour");
        butSetColour.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                boolean validInput = true;
                //attempt to read integers from the text fields
                //if not an integer display the appropriate message and clear text field

                //for red
                try {
                    red = Integer.parseInt(txtfRed.getText());
                } catch (NumberFormatException numberFormatException) {
                    validInput = false;
                    txtfRed.setText("");
                }

                //for green
                try {
                    green = Integer.parseInt(txtfGreen.getText());
                } catch (NumberFormatException numberFormatException) {
                    validInput = false;
                    txtfGreen.setText("");
                }

                //for blue
                try {
                    blue = Integer.parseInt(txtfBlue.getText());
                } catch (NumberFormatException numberFormatException) {
                    validInput = false;
                    txtfBlue.setText("");
                }

                //range check each value and adjust as appropriate then update the message
                if (validInput) {
                    if (red < 0) { red = 200; }
                    else if (red > 255) red = 255;
                    txtfRed.setText(Integer.toString(red));

                    if (green < 0) { green = 200; }
                    else if (green > 255) green = 255;
                    txtfGreen.setText(Integer.toString(green));

                    if (blue < 0) { blue = 200; }
                    else if (blue > 255) blue = 255;
                    txtfBlue.setText(Integer.toString(blue));

                    lblMessage.setText("1704969");
                    lblMessage.setForeground(new Color(red, green, blue));
                } else {
                    lblMessage.setText("You have entered a value that is not an integer");
                    lblMessage.setForeground(Color.black);
                }

            }
        });
        panBottom.add(butSetColour);

        //create the reset button
        JButton butReset = new JButton("reset");
        butReset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                lblMessage.setText("CE203 Assignment 1, submitted by: 1704969");
                lblMessage.setForeground(Color.blue);
                txtfRed.setText("");
                txtfGreen.setText("");
                txtfBlue.setText("");
            }
        });
        panTop.add(butReset);

        this.setVisible(true);
    }
}