package Assignment;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedList;
import java.util.HashMap;

public class CE203_2018_Ex2{

    private JFrame theApp; //reference to the frame
    private JTextArea txtaOutput; //the text area where output is displayed
    private JTextField txtfInput; //the text field that input is taken from
    private LinkedList<String> linkedList; //the list that words are stored in

    private CE203_2018_Ex2() {
        //set up frame
        theApp = new JFrame("Assignment 1 Exercise 2");
        theApp.setLayout(new BorderLayout());
        theApp.setSize(900, 300);
        theApp.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        //set up panel containing buttons
        JPanel panButtons = new JPanel();
        theApp.add(panButtons, BorderLayout.NORTH);
        JButton butAddWord = new JButton("Add word"),
                butDisplaySelect = new JButton("Display words that end with..."),
                butSearch = new JButton("Search"),
                butRemoveLast = new JButton("Remove last occurrence"),
                butRemoveAll = new JButton("Remove all occurences"),
                butClear = new JButton("Clear list");

        //initialise linked list
        linkedList = new LinkedList<>();

        //add action listener to button to add words to list
        butAddWord.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String word = txtfInput.getText().trim();
                if (validWordCheck(word)) {
                    linkedList.add(word);
                    txtaOutput.setText("Word '" + word + "' has been added to the list");
                } else {
                    txtaOutput.setText("The string '" + word + "' was not added to the list as it is not a valid word");
                }
            }
        });

        //add action listener to button to display words that end in a certain letter
        butDisplaySelect.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String letter = txtfInput.getText().trim().toLowerCase();
                if (letter.length() == 1 && validWordCheck(letter)) {
                    boolean wordsMatched = false;
                    String message = "No words found that end in " + letter;
                    for (String listItem : linkedList) {
                        if (listItem.toLowerCase().matches(".*" + letter))
                            if (!wordsMatched) {
                                message = "These words end with " + letter + ": " + listItem;
                                wordsMatched = true;
                            } else {
                                message += ", " + listItem;
                            }
                    }
                    message += ".";
                    txtaOutput.setText(message);
                } else {
                    txtaOutput.setText("Please enter a single valid letter only for this function");
                }
            }
        });

        //add action listener to button to search the list for a certain word
        butSearch.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String search = txtfInput.getText().trim();
                String message = "";
                if (search.equals("")) {
                    HashMap<String, Integer> occsMap = new HashMap<>();
                    for (String listItem : linkedList) {
                        if (occsMap.containsKey(listItem)) {
                            occsMap.put(listItem, occsMap.get(listItem) + 1);
                        } else occsMap.put(listItem, 1);
                    }
                    if (occsMap.isEmpty()) {
                        message = "No words in list.";
                    } else {
                        message = "These words were found: ";
                        for (String key : occsMap.keySet()) {
                            message += key + " (" + occsMap.get(key) + " times), ";
                        }
                    }


                } else {
                    int occs = 0;
                    int i = 0;
                    for (String listItem : linkedList) {
                        if (listItem.equals(search)) {
                            if (occs == 0) message = "'" + search + "' found at position(s): " + i;
                            else {
                                message += ", " + i;
                            }
                            occs++;
                        }
                        i++;
                    }
                    if (occs == 0) message = "No occurrences of '" + search + "' found.";
                    else message += ". (" + occs + " times)";
                }

                txtaOutput.setText(message);

            }
        });

        //add action listener to button to remove the last occurrence of a word
        butRemoveLast.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String wordToDelete = txtfInput.getText().trim();
                if (validWordCheck(wordToDelete)) {
                    linkedList.removeLastOccurrence(wordToDelete);
                    txtaOutput.setText("Removed last occurrence of '" + wordToDelete + "'.");
                } else {
                    txtaOutput.setText("Cannot remove as you have not entered a valid word");
                }
            }
        });

        //add action listener to button to remove all occurrences of a word
        butRemoveAll.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String wordToDelete = txtfInput.getText().trim();
                if (validWordCheck(wordToDelete)) {
                    while (linkedList.contains(wordToDelete)) linkedList.removeLastOccurrence(wordToDelete);
                    txtaOutput.setText("Removed all occurrences of '" + wordToDelete + "'.");
                } else {
                    txtaOutput.setText("Cannot remove as you have not entered a valid word");
                }
            }
        });

        //add action listener to button to clear the list
        butClear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                linkedList.clear();
                txtaOutput.setText("List cleared of all words.");
            }
        });

        //then add buttons to panel
        panButtons.add(butAddWord);
        panButtons.add(butDisplaySelect);
        panButtons.add(butSearch);
        panButtons.add(butRemoveLast);
        panButtons.add(butRemoveAll);
        panButtons.add(butClear);

        //set up the input
        JPanel panText = new JPanel();
        theApp.add(panText, BorderLayout.SOUTH);
        txtfInput = new JTextField(75);
        panText.add(txtfInput);

        //set up the output
        JPanel panOutput = new JPanel();
        theApp.add(panOutput, BorderLayout.CENTER);
        txtaOutput = new JTextArea();
        txtaOutput.setBackground(theApp.getBackground());
        txtaOutput.setAlignmentY(Component.CENTER_ALIGNMENT);
        txtaOutput.setAlignmentX(Component.CENTER_ALIGNMENT);
        txtaOutput.setLineWrap(true);
        txtaOutput.setColumns(50);
        panOutput.add(txtaOutput);

        theApp.setVisible(true);
    }

    public static void main(String[] args) {
        new CE203_2018_Ex2();
    }

    private boolean validWordCheck(String s) {
        // method takes a string and checks if it contains only letters, numbers or hyphens and begins with a letter-- using a Regular Expression
        return s.matches("([A-Z]|[a-z])([A-Z]|[a-z]|-|[0-9])*");
    }

}
