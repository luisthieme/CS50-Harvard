import { initializeApp } from "https://www.gstatic.com/firebasejs/9.0.2/firebase-app.js";
import { getDatabase, ref, push, onValue, set} from "https://www.gstatic.com/firebasejs/9.0.2/firebase-database.js";

const btn = document.querySelector("#button");
const btnText = document.querySelector("#buttonText");

const firebaseConfig = {
    apiKey: "AIzaSyBiXfw2lp0Cohkx9nSVyrM2Ngdh5pafN7U",
    authDomain: "comment-section-1ba02.firebaseapp.com",
    databaseURL: "https://comment-section-1ba02-default-rtdb.europe-west1.firebasedatabase.app",
    projectId: "comment-section-1ba02",
    storageBucket: "comment-section-1ba02.appspot.com",
    messagingSenderId: "520844816450",
    appId: "1:520844816450:web:71a0e02256cfb6e4227ddb",
    measurementId: "G-MDK6ZDSMRX"
};
  
const app = initializeApp(firebaseConfig);
const db = getDatabase(app);


btn.onclick = () => {
    btnText.innerHTML = "Thanks";
    btn.classList.add("active");
};

document.getElementById('comment-form').addEventListener('submit', function(event) {
event.preventDefault();
});

document.getElementById('button').addEventListener('click', function() {
    const inputText = document.getElementById('comment-text').value.trim();

    if(inputText !== '') {
        const newParagraphRef = push(ref(db, 'paragraphs'));
        set(newParagraphRef, {text: inputText});

        document.getElementById('comment-text').value = '';
    }
});

onValue(ref(db, 'paragraphs'), (snapshot) => {
    const outputElement = document.getElementById('commentSectionIndex');
    outputElement.innerHTML = '';
  
    snapshot.forEach((childSnapshot) => {
      const paragraphText = childSnapshot.val().text;
      const newParagraph = document.createElement('p');
      newParagraph.textContent = paragraphText;
      outputElement.appendChild(newParagraph);
      console.log('works');
    });
  });






  





