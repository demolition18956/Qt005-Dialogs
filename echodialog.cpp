// echodialog.cpp -- EchoDialog implementation file
#include "echodialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>


EchoDialog::EchoDialog()
{
	// Allocate layouts
	QVBoxLayout* mainLayoutPtr = new QVBoxLayout(this);
	QVBoxLayout* inputLayoutPtr = new QVBoxLayout;
	QGridLayout* echoLayoutPtr = new QGridLayout;
	QHBoxLayout* buttonLayoutPtr = new QHBoxLayout;
	
	setWindowTitle("Double Echo Dialog");		// Set dialog title
	
	// Build main dialog layout
	mainLayoutPtr->addLayout(inputLayoutPtr);	// Place input layout at top
	mainLayoutPtr->addStretch();				// Add Stretch
	mainLayoutPtr->addLayout(echoLayoutPtr);	// Place echo layout in middle
	mainLayoutPtr->addStretch();				// Add stretch
	mainLayoutPtr->addLayout(buttonLayoutPtr);	// Place button layout at bottom
	
	// Build input layout
	QLabel* inputLabelPtr = new QLabel("Type your input below");	// Allocate and
	
	userInputLineEditPtr = new QLineEdit;
	userInputLineEditPtr->setMaxLength(MAXIMUM_LENGTH);
	userInputLineEditPtr->setFrame(true);
	
	inputLayoutPtr->addWidget(inputLabelPtr);
	inputLayoutPtr->addWidget(userInputLineEditPtr);
	
	// Build echo layout
	QLabel* firstLabelPtr = new QLabel("QLabel Echo");
	QLabel* secondLabelPtr = new QLabel("QLineEdit Echo");
	
	echoLabelPtr = new QLabel;
	echoLabelPtr->setFrameShape(QFrame::Box);
	echoLineEditPtr = new QLineEdit;
	echoLineEditPtr->setReadOnly(true);
	echoLineEditPtr->setMaxLength(MAXIMUM_LENGTH);
	echoLineEditPtr->setFrame(true);
	
	echoLayoutPtr->addWidget(firstLabelPtr,0,0);
	echoLayoutPtr->addWidget(echoLabelPtr,0,1);
	echoLayoutPtr->addWidget(secondLabelPtr,1,0);
	echoLayoutPtr->addWidget(echoLineEditPtr,1,1);
	
	// Build close button layout
	clearButtonPtr = new QPushButton("Clear");
	quitButtonPtr = new QPushButton("Quit");
	
	quitButtonPtr->setDefault(true);
	buttonLayoutPtr->addWidget(clearButtonPtr);
	buttonLayoutPtr->addStretch();
	buttonLayoutPtr->addWidget(quitButtonPtr);
	
	
	connect(quitButtonPtr,SIGNAL(clicked()), this, SLOT(accept()));
	connect(clearButtonPtr, SIGNAL(clicked()), userInputLineEditPtr, SLOT(clear()));
	QObject::connect(userInputLineEditPtr, SIGNAL(textChanged(QString)), echoLabelPtr, SLOT(setText(QString)));
	QObject::connect(userInputLineEditPtr, SIGNAL(textChanged(QString)), echoLineEditPtr, SLOT(setText(QString)));
}


