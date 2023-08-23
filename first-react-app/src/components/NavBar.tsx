import '../../css/styles.css'
import NavBarLinks from './NavBarLinks';
import { useState, useEffect } from 'react';

interface linkObjekts {
    id: number;
    linkTitle: string;
    linkSrc: string;
}

interface link {
    id: number;
    linkTitle: string;
    linkSrc: string;
}


interface NavBarProps {
    pageTitle: string;
    pageLinks: linkObjekts[];
}

export default function NavBar( props: NavBarProps ) {
    const [windowWidth, setWindowWidth] = useState(window.innerWidth);
    const [hiddenElementsVisible, setHiddenElementsVisible] = useState(true);

    useEffect(() => {
        const handleResize = () => {
        setWindowWidth(window.innerWidth);
        };

        window.addEventListener('resize', handleResize);

        return () => {
        window.removeEventListener('resize', handleResize);
        };
    }, []);

    const toggleHiddenElements = () => {
        setHiddenElementsVisible(!hiddenElementsVisible);
    };

    function handleActive(link: link): boolean { //better way to do this?
        if(link.linkTitle === props.pageTitle) {
            return true;
        }
        return false;
    }

    return (
        <div className="navBarContainer">
            <div className="navBarTitleContainer">
                <h1 className="pageTitle">{ props.pageTitle }</h1>
            </div>
            <div className={`showOnSmallScreen ${windowWidth < 500 ? '' : 'hidden'} dropDownButtonContainer`}>
                <button className="dropDownButton" onClick={toggleHiddenElements}>MENU</button>
            </div>
            <div className={`hideOnSmallScreen ${windowWidth < 500 && hiddenElementsVisible ? 'hidden ' : 'navBarLinksContainer navBarLinksContainerSmall'}`}>
                {props.pageLinks.map(link => (
                    <NavBarLinks isActive={handleActive(link)} key={link.id} linkTitle={link.linkTitle} linkSrc={link.linkSrc}></NavBarLinks>
                ))}
            </div>
            <hr />
        </div>
    );
}
