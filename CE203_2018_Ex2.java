package Assignment;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedList;
import java.util.HashMap;

public class CE203_2018_Ex2 {

    private JFrame theApp;
    private JTextArea txtaOutput;
    private JTextField txtfInput;
    private LinkedList<String> linkedList;

    private CE203_2018_Ex2() {
        theApp = new JFrame("Assignment 1 Exercise 2");
        theApp.setLayout(new BorderLayout());
        theApp.setSize(900, 300);
        theApp.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        JPanel panButtons = new JPanel();
        theApp.add(panButtons, BorderLayout.NORTH);
        JButton butAddWord = new JButton("Add word"),
                butDisplaySelect = new JButton("Display words that end with..."),
                butSearch = new JButton("Search"),
                butRemoveLast = new JButton("Remove last occurrence"),
                butRemoveAll = new JButton("Remove all occurences"),
                butClear = new JButton("Clear list");

        linkedList = new LinkedList<>();
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
                    txtaOutput.setText(message.toString());
                } else {
                    txtaOutput.setText("Please enter a single valid letter only for this function");
                }
            }
        });

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
                            i++;
                        }
                    }
                    if (occs == 0) message = "No occurrences of '" + search + "' found.";
                }

                txtaOutput.setText(message);

            }
        });

        butRemoveLast.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String wordToDelete = txtfInput.getText().trim();
                linkedList.removeLastOccurrence(wordToDelete);
                txtaOutput.setText("Removed last occurrence of " + wordToDelete + "'.");
            }
        });

        butRemoveAll.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String wordToDelete = txtfInput.getText().trim();
                while (linkedList.contains(wordToDelete)) linkedList.removeLastOccurrence(wordToDelete);
                txtaOutput.setText("Removed all occurrences of '" + wordToDelete + "'.");
            }
        });

        butClear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                linkedList.clear();
                txtaOutput.setText("List cleared of all words.");
            }
        });
        panButtons.add(butAddWord);
        panButtons.add(butDisplaySelect);
        panButtons.add(butSearch);
        panButtons.add(butRemoveLast);
        panButtons.add(butRemoveAll);
        panButtons.add(butClear);

        JPanel panText = new JPanel();
        theApp.add(panText, BorderLayout.SOUTH);
        txtfInput = new

                JTextField(75);
        panText.add(txtfInput);

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
        return s.matches("([A-Z]|[a-z]|-|[0-9])*");
    }
}
